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
#include <stdbool.h>
#include <getopt.h>

/**
 * @brief Minimum number of arguments that will be accepted by vman.
 *
 * This MACRO can be used to check the minimum number of arguments provided to
 * vman at the time of running and provide a proper response based on the same.
 */
#ifndef MIN_ARGC
#define MIN_ARGC 2
#endif

/**
 * @brief Custom binary directory location.
 *
 * This MACRO can be used to specify the custom binary directory. This
 * directory will be containing all the symlinks of the programs configured to
 * be managed by vman.
 */
#ifndef CUSTOM_BIN
#define CUSTOM_BIN "~/.cbin"
#endif

/**
 * @brief vman configuration directory location
 *
 * This MACRO can be used to specify vman configuration directory location.
 * This is the location where vman will be maintaining all the files for
 * managing all the programs specified inside it.
 */
#ifndef VMAN_CONFIG_DIR
#define VMAN_CONFIG_DIR "~/.config/vman"
#endif

#ifndef LOG_FILENAME
#define LOG_FILENAME "run.log"
#endif

/**
 * @brief vman configuration filename.
 *
 * This MACRO can be used to specify the vman configuration filename. This
 * configuration file will be present inside ~/.config/vman or as defined above
 * inside the VMAN_CONFIG_DIR location.
 */
#ifndef VMANRC
#define VMANRC "vmanrc"
#endif

/**
 * @brief ProgramMode enum to be used in order to select the run mode.
 *
 * vman can be run to either add a new program or add a new install location to
 * an already added program. This would be handled by the Program mode of ADD.
 *
 * When vman needs to select the right install location, it needs to be run in
 * CONFIGURE mode in order to select the right install location.
 */
enum ProgramMode {
	ADD,
	CONFIGURE
};

/**
 * @brief Structure to containing the run configuration when vman is run.
 *
 * This struct can be used to maintain the instance of run configuration used
 * to run vman in order to either ADD or CONFIGURE a program and respective
 * install location.
 */
typedef struct {
	enum ProgramMode mode;
	bool enable_debug;
	bool lts, ltf; /* ltf - log to file, lts - log to stream */
} runconfg_t;

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

/**
 * @brief Function to setup the pre-requisites.
 *
 * This function can be used in order to setup the pre-requisites like the
 * custom binary directory, program configuration storage location and other
 * necessities which are required for vman to operate properly.
 *
 * @param void - no arguments are required for this function to perform.
 *
 * @return Returns 0 on success, -1 on failure.
 *
 * @note This function will also be responsible for setting up the logging.
 */
int vman_setup_prereq(runconfg_t *rconfig);
