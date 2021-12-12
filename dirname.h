#ifndef DIRNAME_H_
#define DIRNAME_H_

/* Simple dirname function. It works like a POSIX.1-2008 realpath() in terms of
 * what arguments you are passing to it, but acts like a POSIX dirname.
 * I think it's more safer and easier to use instead of libgen.h version.
 */

#ifndef _DEFAULT_SOURCE
# error "Please, define _DEFAULT_SOURCE or whatever it needs to make use of POSIX headers."
#endif
#include <limits.h>	/* PATH_MAX */
#include <string.h>	/* memcpy */

static inline char *dirname(const char *restrict path,
		char *restrict dir_path)
{
	if (dir_path == NULL)
		goto fatal_error;

	int i = 0,
	       name_end = (-1),
	       last_nonslash = (-1);
	int prev_is_slash = 0;
	char s;

	// First symbol is special.
	{
		s = path[i];
		switch(s) {
		case '\0':
			goto currentdir;
		case '/':
			name_end = i;
			last_nonslash = i;
			break;
		default:
			last_nonslash = i;
		}
		i++;
	}

	do {
		s = path[i];
		switch (s) {
		case '\0':
			goto endofstring;
		case '/':
			prev_is_slash = 1;
			break;
		default:
			if (prev_is_slash)
				name_end = last_nonslash;
			last_nonslash = i;
			prev_is_slash = 0;
		}
		i++;
	} while (i < PATH_MAX);

	// Very last symbol needs to be '\0'
	if (path[i] != '\0')
		goto fatal_error;
	/* fall-through */
endofstring:;
	if (name_end == (-1))
		goto currentdir;
	memcpy(dir_path, path, name_end + 1);
	dir_path[name_end + 1] = '\0';
	goto normal;

currentdir:;
	dir_path[0] = '.';
	dir_path[1] = '\0';
	/* fall-through */
normal:;
	return dir_path;

fatal_error:;
	return NULL;
}


#endif /* DIRNAME_H_ */
