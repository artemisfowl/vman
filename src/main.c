/**
 * @file main.c
 * @brief Program for switching between multiple installed versions of programs.
 *
 * @description This program can be used in order to manage switching between
 * multiple versions of programs installed in different locations by allowing
 * the user to select the configured version at runtime.
 *
 * @author oldgod
 * @date Tue, 19 Nov 2024 06:58:52 +0530
 * @bug No known bugs as of now.
 *
 * @note This program will automatically update bash configuration file
 * (~/.bashrc) unless specified what is the default shell being used. If the
 * default shell is specified, then this program will try to update the
 * specified shell file.
 */

#include "../inc/vman.h"

/* fixme: Testing include block - remove after done */
/* fixme: Testing include block - remove after done */

/**
 * TODO:
 * Add a function to check the number of arguments passed.
 * Add function to parse arguments (including long arguments).
 * Add function to create directories (including recursive ones).
 *
 * COMPLETE:
 * Add function to show the program version.
 * Add function to show the program usage.
 */

int main(int argc, char *argv[])
{
	/* prepare the options (short and long) to be parsed */
	struct option long_options[] = {
		{"add", required_argument, NULL, 'a'},
		{"config", required_argument, NULL, 'c'},
		{"version", required_argument, NULL, 'v'},
		{"debug", required_argument, NULL, 'd'},
		{NULL, 0, NULL, 0}
	};
	char short_options[] = "vda:c:";

	/* start parsing the arguments */
	if (vman_chkargs(argc, argv, MIN_ARGC, short_options, long_options)) {
		fprintf(stderr, "Error while parsing CLI arguments\n");
		return -1;
	}

	return 0;
}
