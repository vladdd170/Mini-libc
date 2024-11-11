#include <errno.h>
#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <string.h>

int puts(const char *string) {
    int len = strlen(string);

    int sir1 = write(1, string, len);
    int sir2 = write(1, "\n", 1);

    if (sir1 < 0) {
      errno = -sir1;
      return -1;
    }

    if (sir2 < 0) {
      errno = -sir2;
      return -1;
    }

    return sir1;
}
