/**
 * @file vman.c
 * @brief Source file containing the implementation of basic usage routines.
 *
 * @description This header file will be containing all the routines to be
 * used specifically for this program.
 *
 * @author oldgod
 * @date Tue, 19 Nov 2024 07:07:22 +0530
 * @bug No known bugs as of now.
 */

#include "../inc/vman.h"
#include "../inc/argparse.h"
#include "../inc/buildinfo.h"
#include "../inc/io.h"
#include "../inc/log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/limits.h>
#include <sys/stat.h>

void vman_usage(void)
{
	printf("vman usage:\n"
		"vman [OPTION[VALUES]]\n"
		"Options:\n"

		"\t-v, --version: Show the version of this program.\n"
		"\t-d, --debug: Enable debug logging for the run.\n"
	);
}

void vman_version(void)
{
	printf("vman v%d.%d build %d\n", MAJOR, MINOR, BUILD_NUMBER);
}

int vman_chkargs(int argc, char **argv, int r_argc, char *s_args,
		struct option *l_options)
{
	if (!r_argc) {
		fprintf(stderr, "Required arguments could not be 0\n");
		return -1;
	} else if (argc < r_argc) {
		fprintf(stderr, "Too few arguments...\n");
		vman_usage();
		return -1;
	}

	if (!s_args || strlen(s_args) == 0) {
		fprintf(stderr, "Short arguments not provided\n");
		return -1;
	}

	return argparse_parse(argc, argv, l_options, s_args);
}

int vman_setup_prereq(runconfg_t *rconfig)
{
	if (!rconfig) {
		fprintf(stderr, "Runtime configuration "
				"struct instance not provided\n");
		return -1;
	}

	/**
	 * FIXME:
	 * Call the function to create the respective directory.
	 * Call the function for setting up logging.
	 * Write an info if the logging is set to INFO, else a debug log if the
	 * logging is set to DEBUG.
	 *
	 * Call the function for creating directories recursively.
	 * Create the custom binary directory.
	 * Create the vman configuration directory.
	 *
	 * Call the function to check if the vman configuration file is present
	 * or not.
	 * Create the vman configuration file if it is not present.
	 *
	 * DONE:
	 */

	int result = 0;

	/* TODO: create the custom binary directory */

	/* setting up logging */
	char *logfpath = io_resolve_path(VMAN_CONFIG_DIR);

	printf("vman config directory: %s\n", VMAN_CONFIG_DIR);
	printf("Resolved log filepath: %s\n", logfpath);

	/* TODO: create the vman configuration directory if it does
	 * not exist */
	if (!io_path_exists(logfpath)) {
		if (io_mkdir(logfpath, S_IRWXU, TRUE)) {
			fprintf(stderr, "Error while creating log path: %s\n",
					logfpath);
			free(logfpath);
			return -1;
		}
	}

	/* logfpath = strcat(logfpath, LOG_FILENAME); */
	/* debug("Final log filepath: %s\n", logfpath); */

	/* if (rconfig->enable_debug) { */
	/* 	log_init(logfpath, DEBUG); */
	/* 	rconfig->ltf = true; */
	/* 	rconfig->lts = true; */
	/* } else { */
	/* 	log_init(logfpath, INFO); */
	/* 	rconfig->ltf = true; */
	/* 	rconfig->lts = false; */
	/* } */
	/* log_set_stream(rconfig->lts, rconfig->ltf); */

	/* info("Setting up vman prerequisites..."); */

	/* TODO: setup the custom binary directory */
	/* debug("Setting up custom binary location: %s", CUSTOM_BIN); */

	free(logfpath);
	return result;
}
