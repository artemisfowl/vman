/**
 * @file argparse.h
 * @brief Header file containing the routines for parsing and manipulating
 * CLI arguments.
 *
 * @description This header file will be containing all the routines to be
 * used specifically for parsing CLI arguments as well as manipulating the same.
 *
 * @author oldgod
 * @date Tue, 19 Nov 2024 08:23:12 +0530
 * @bug No known bugs as of now.
 */

#include <stdio.h>
#include <getopt.h>

/**
 * @brief Function to parse the CLI arguments and store the same in a Runtime
 * Configuration instance.
 *
 * This function can be used in order to parse the CLI arguments, including
 * long arguments.
 *
 * @param argc - integer containing the argument count.
 * @param argv - array of strings containing all the arguments (including the
 * option names).
 * @param long_options - struct option instance for containing the long CLI
 * option names.
 * @param options - string containing the short option names.
 *
 * @return Returns 0 on success, -1 on failure.
 *
 * @note Need to update the return properly.
 */
int argparse_parse(int argc, char *argv[],
		struct option *long_options, const char *options);
