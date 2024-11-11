// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	// sys_close = 3;
	int rezultat = syscall(3, fd);

        if (rezultat < 0) {
          errno = -rezultat;
          return -1;
        }

        return rezultat;
}
