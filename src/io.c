#include "../inc/io.h"

int io_mkdir(const char *path, const mode_t mode, bool recursive)
{
	if (!path) {
		return -1;
	}

	if (recursive) {
		/* implement the recursive directory building */
	} else {
		/* implement the single directory building */
	}

	return 0;
}
