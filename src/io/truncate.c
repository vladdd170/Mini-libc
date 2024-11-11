// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <unistd.h>

int truncate(const char *path, off_t length) {
  /* TODO: Implement truncate(). */
  // sys_truncate = 76
  int ret = syscall(76, path, length);

  if (ret < 0) {
    errno = -ret;
    return -1;
  }

  return ret;
}
