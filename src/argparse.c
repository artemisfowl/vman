#include "../inc/argparse.h"

int argparse_parse(int argc, char **argv,
		struct option *long_options, const char *options)
{

	if (!options) {
		fprintf(stderr, "Error: No short options provided...\n");
		return -1;
	}

	int result = 0;
	if (!long_options) {
		fprintf(stderr, "Warning: No long options provided...\n");
		result = getopt(argc, argv, options);
	} else {
		result = getopt_long(argc, argv, options, long_options, NULL);
	}

	return result;
}
