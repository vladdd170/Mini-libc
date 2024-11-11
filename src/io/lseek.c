// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <unistd.h>

off_t lseek(int fd, off_t offset, int whence) {
  /* TODO: Implement lseek(). */
  // sys_lseek = 8
  off_t res = syscall(8, fd, offset, whence);

  if (res < 0) {
    errno = -res;
    return -1;
  }

  return res;
}
