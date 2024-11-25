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
		return -1;
	}

	if (recursive) {
		/* implement the recursive directory building */
		char copy[strlen(path)+1];
		memset(copy, '\0', strlen(path)+1);
		memcpy(copy, path, strlen(path));
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
		return result;
	}

	char copy[strlen(path)+1];
	memset(copy, '\0', strlen(path)+1);
	memcpy(copy, path, strlen(path));

	char *rpath = io_resolve_path(copy);
	if (rpath == NULL)
		warning("Resolution not required, path already proper");

	struct stat details;
	result = stat(rpath, &details);
	printf("Value of stat call: %d\n", result);
	free(rpath);
	return result == 0 ? TRUE : FALSE;
}
