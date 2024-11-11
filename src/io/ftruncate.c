// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	// sys_ftruncate = 77
	long int resz = syscall(77, fd, length);

        if (resz < 0) {
          errno = -resz;
          return -1;
        }

        return resz;
}
