#include "../inc/io.h"
#include "../inc/log.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

int io_mkdir(const char *path, const mode_t mode, bool recursive)
{
	if (!path || strlen(path) == 0) {
		error("Path to be created is not specified");
		fprintf(stderr, "Path to be created is not specified\n");
		return -1;
	}

	if (recursive) {
		/* implement the recursive directory building */
		char copy[strlen(path)+1], tmp[strlen(path)+1];

		memset(tmp, '\0', strlen(path)+1);
		memset(copy, '\0', strlen(path)+1);
		memcpy(copy, path, strlen(path));

		/* if the path is unresolved or in root (/) then do not perform
		 * any action */
		if (copy[0] == '~' && copy[1] == '/') {
			error("Relative path provided, "
					"please provide resolved path");
			fprintf(stderr, "Relative path provided, "
					"please provide resolved path\n");
			return -1;
		} else if (copy[0] == '/') {
			/* present from the root */
			tmp[0] = '/';
		} else if (copy[0] == '.' && copy[1] == '/') {
			/* relative to the current directory */
			tmp[0] = '.';
			tmp[1] = '/';
		}

		for (char *token = strtok(copy, "/"); token != NULL;
				token = strtok(NULL, "/")) {
			/* update tmp */
			char *str_result = strncat(tmp, token, strlen(token)+1);
			debug("Result of token concatenation: %s", str_result);
			str_result = strncat(tmp, "/", strlen("/")+1);
			debug("Result of separator concatenation: %s",
					str_result);

			if (!io_path_exists(tmp)) {
				printf("Path specified: %s does not "
						"exist\n", tmp);
				if (mkdir(tmp, mode)) {
					error("Failed while trying to "
							"create: %s",
							tmp);
					return -1;
				}
			} else {
				printf("Path specified: %s exists\n", tmp);
			}
		}
	} else {
		/* implement the single directory building */
	}

	return 0;
}

char *io_resolve_path(const char *s)
{
	if (!s) {
		error("String to be resolved not specified");
		return NULL;
	}

	info("About to resolve the specified string...");
	debug("String [specified]: %s", s);

	char *rpath = NULL;

	if (s[0] == '~' && s[1] == '/') {
		info("Path is relative to $HOME directory, resolving...");

		rpath = (char *)calloc(strlen(s), sizeof(char));
		rpath = strcat(rpath, getenv("HOME"));
		rpath = strcat(rpath, "/");

		char copy[strlen(s)+1];
		memset(copy, '\0', strlen(s)+1);
		memcpy(copy, s, strlen(s));

		for (char *token = strtok(copy, "/"); token != NULL;
				token = strtok(NULL, "/")) {
			if (strcmp(token, "~")) {
				rpath = strcat(rpath, token);
				rpath = strcat(rpath, "/");
			}
		}

	} else {
		warning("Path is already reference properly with "
				"respect to $HOME directory");
	}

	debug("Final resolved path: %s", rpath);
	return rpath;
}

bool io_path_exists(const char *path)
{
	int result = FALSE;
	if (!path || strlen(path) == 0) {
		error("Path to be checked not specified");
		fprintf(stderr, "Path to be checked not specified\n");
		return result;
	}

	char copy[strlen(path)+1];
	memset(copy, '\0', strlen(path)+1);
	memcpy(copy, path, strlen(path));

	struct stat details;
	result = stat(copy, &details);
	return result == 0 ? TRUE : FALSE;
}
