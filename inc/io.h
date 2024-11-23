/**
 * @file io.h
 * @brief Header file containing the generic I/O routines.
 *
 * @description This header file will be containing all the routines that can
 * be used for performing various I/O.
 *
 * @author oldgod
 * @date Tue, 19 Nov 2024 07:51:03 +0530
 * @bug No known bugs as of now.
 */

#include <stdbool.h>
#include <sys/types.h>

/**
 * @brief Function to create the directories specified in the path.
 *
 * This function can be used to create a single directory as well as to create
 * all the directories provided in the path.
 *
 * @param path - string containing the path to the directory.
 * @param mode - mode type for the directory to be created.
 * @param recursive - boolean, TRUE for recursively creating the directories in
 * the path, FALSE for non-recursive - meaning only create the last directory
 * in the specified path.
 *
 * @return Returns 0 on success, -1 on failure.
 */
int io_mkdir(const char *path, const mode_t mode, bool recursive);
