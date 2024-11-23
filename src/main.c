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
#include <stdbool.h>
#include <stdio.h>

/* FIXME: Testing include block - remove after done */
/* FIXME: Testing include block - remove after done */

/**
 * TODO:
 * Add the constants related to vman.
 * Add function to create directories (including recursive ones).
 *
 * COMPLETE:
 * Add function to perform operations based on CLI options.
 * Add function to parse arguments (including long arguments).
 * Add function to show the program version.
 * Add function to show the program usage.
 * Add a function to check the number of arguments passed.
 */

int main(int argc, char *argv[])
{
	/**
	 * prepare the options (short and long) to be parsed
	 * Options mapping:
	 * -a, --add: for adding a new program and respective install location.
	 * -c, --config: for configuring an already configured program.
	 * -v, --version: for showing the program version.
	 * -d, --debug: for enabling debug run.
	 * -h, --help: for showing the program usage details.
	 */
	struct option long_options[] = {
		{"add", required_argument, NULL, 'a'},
		{"config", required_argument, NULL, 'c'},
		{"version", no_argument, NULL, 'v'},
		{"debug", no_argument, NULL, 'd'},
		{"help", no_argument, NULL, 'h'},
		{NULL, 0, NULL, 0}
	};
	char short_options[] = "vdha:c:";

	/* debug and program mode */
	runconfg_t rconfig;
	rconfig.enable_debug = false;
	rconfig.ltf = true;
	rconfig.lts = false;

	/* start parsing the arguments */
	switch (vman_chkargs(argc, argv, MIN_ARGC,
				short_options, long_options)) {
		case 'v':
			vman_version();
			break;
		case 'h':
			vman_usage();
			break;
		case 'd':
			rconfig.enable_debug = true;
			break;
		case 'a':
			printf("Adding the program\n");
			rconfig.mode = ADD;
			break;
		case 'c':
			printf("Configuring the specified program\n");
			rconfig.mode = CONFIGURE;
			break;
	}

	if (vman_setup_prereq(&rconfig)) {
		fprintf(stderr, "Error while setting up pre-requisites\n");
		/* FIXME: add the error logging for this one */
		return -1;
	}

	/* FIXME: implement the code for performing the operations */

	return 0;
}
