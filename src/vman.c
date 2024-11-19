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
#include "../inc/buildinfo.h"
#include <stdio.h>

void vman_usage(void)
{
	printf("vman usage:\n"
		"vman [OPTION[VALUES]]\n"
		"Options:\n"

		"\t-v, --version: Show the version of this program\n"
	);
}

void vman_version(void)
{
	printf("vman v%d.%d build %d\n", MAJOR, MINOR, BUILD_NUMBER);
}
