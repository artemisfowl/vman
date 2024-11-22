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
#include <string.h>

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

	/* fixme: start implementing the parsing using the argparse translation
	 * units */

	return 0;
}
