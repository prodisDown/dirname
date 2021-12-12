#define _DEFAULT_SOURCE
#include <stdio.h>	/* output purpose */
#include <sys/types.h>	/* primitive types */
#include <limits.h>	/* PATH_MAX, NAME_MAX, etc. */

#include <stdlib.h>	/* malloc, calloc, etc. */
#include <unistd.h>	/* symbolic constants, read, write, etc. */
#include <fcntl.h>	/* file control operations */
#include <dirent.h>	/* directory operations */

#include "dirname.h"	/* using my custom dirname function */

int main(int argc, char *argv[])
{
	if (argc < 2) exit(1);

	char dirname_buf[PATH_MAX] = {0};
	char **arg;
	for (arg = &argv[1]; *arg; arg++)
		puts(dirname(*arg, dirname_buf));

	exit(0);
}
