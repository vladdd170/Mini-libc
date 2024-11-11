// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	// obtin flagurile

	// sys_open = 2
	int rezo = syscall(2, filename, flags);

	if (rezo < 0) {
          errno = -rezo;
          return -1;
        }


	return rezo;
}
