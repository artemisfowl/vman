/**
 * @file vman.h
 * @brief Header file containing the basic usage routines.
 *
 * @description This header file will be containing all the routines to be
 * used specifically for this program.
 *
 * @author oldgod
 * @date Tue, 19 Nov 2024 06:58:52 +0530
 * @bug No known bugs as of now.
 */

#include <stdio.h>
#include <getopt.h>

#ifndef MIN_ARGC
#define MIN_ARGC 2
#endif

/**
 * @brief Function to show the usage of this program.
 *
 * This function can be used in order to show the options available for this
 * program.
 *
 * @param void - no arguments will be accepted by this program.
 *
 * @note The help information will be updated as and when the development goes
 * ahead for this program.
 */
void vman_usage(void);

/**
 * @brief Function to show the version of this program.
 *
 * This function can be used in order to show the program version.
 *
 * @param void - no arguments will be accepted by this program.
 */
void vman_version(void);

/**
 * @brief Function to check the number of required arguments as well as parse
 * the CLI arguments.
 *
 * This is a program specific function to be used for checking the number of
 * arguments as well as for parsing the CLI arguments provided.
 *
 * @param argc - integer containing the argument count.
 * @param argv - string array containing all the CLI arguments.
 * @param r_argc - integer containing the minimum required argument count.
 * @param s_args - string containing the short argument flags for arg parsing.
 * @param l_options - option instance for parsing long options.
 *
 * @return Returns 0 on success, -1 on failure.
 *
 * @note If no long options are to be parsed, send NULL for this one.
 */
int vman_chkargs(int argc, char *argv[], int r_argc, char *s_args,
		struct option *l_options);
