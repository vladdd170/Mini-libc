// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source) {
  char *copie = destination;
  while (*source) {
    *destination++ = *source++;
  }
  *destination = '\0';
  destination = copie;
  return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {
  char *copie = destination;
  while (len && *source) {
    *destination++ = *source++;
    len--;
  }

  while (len) {
    *destination++ = '\0';
    len--;
  }

  return copie;
}

char *strcat(char *destination, const char *source) {
  char *copie = destination;

  while (*destination != '\0') destination++;

  while (*source != '\0') *destination++ = *source++;

  *destination = '\0';
  destination = copie;

  return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
  char *copie = destination;

  while (*destination != '\0')
    destination++;

  for (size_t i = 0; i < len; i++) {
    *destination++ = *source++;
  }

  *destination = '\0';
  destination = copie;

  return destination;
}

int strcmp(const char *str1, const char *str2) {
  // Pt codul ascii
  const unsigned char *s1 = (const unsigned char *)str1;
  const unsigned char *s2 = (const unsigned char *)str2;

  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }

  return *s1 - *s2;
}

int strncmp(const char *str1, const char *str2, size_t len) {
  const unsigned char *s1 = (const unsigned char *)str1;
  const unsigned char *s2 = (const unsigned char *)str2;

  while (len && *s1 && (*s1 == *s2)) {
    s1++;
    s2++;
    len--;
  }

  if (len == 0) {
    return 0;
  } else {
    return *s1 - *s2;
  }
}

size_t strlen(const char *str) {
  size_t i = 0;
  for (; *str != '\0'; str++, i++)
    continue;
  return i;
}

char *strchr(const char *str, int c) {
  while (*str) {
    if (*str == (char) c) {
      return (char *)str;
    }
    str++;
  }

  if (c == '\0')
    return NULL;

  return NULL;
}

char *strrchr(const char *str, int c) {
  char *copie = NULL;

  while (*str) {
    if ( *str == (char)c ) {
      copie = (char *)str;
    }
    str++;
  }

  if (c == '\0')
    return (char *)str;

  return copie;
}

char *strstr(const char *haystack, const char *needle) {
  if (*needle == '\0')
    return (char *)haystack;

  while (*haystack) {
    const char *copieH = haystack;
    const char *copieN = needle;
    while (*copieH != '\0' && *copieN != '\0' && *copieN == *copieH) {
      copieH++;
      copieN++;
    }

  if (*copieN == '\0')
    return (char *)haystack;

  haystack++;
  }

  return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
  /* TODO: Implement strrstr(). */
  if (*needle == '\0')
    return (char *)haystack;

  const char *copie = NULL;

  while (*haystack) {
    const char *copieH = haystack;
    const char *copieN = needle;
    while (*copieH != '\0' && *copieN != '\0' && *copieN == *copieH) {
      copieH++;
      copieN++;
    }

    if (*copieN == '\0')
      copie = haystack;

    haystack++;
  }

  return (char *)copie;
}

void *memcpy(void *destination, const void *source, size_t num) {
  /* TODO: Implement memcpy(). */
  char *destinatie = (char *) destination;
  char *sursa = (char *)source;
  int maxim = (int) num;

  for (int i = 0; i < maxim ; i++)
    destinatie[i] = sursa[i];

  return destination;
}

void *memmove(void *destination, const void *source, size_t num) {
  /* TODO: Implement memmove(). */
  char *destinatie = (char *)destination;
  const char *sursa = (const char *)source;
  int maxim =(int)num;

  if ( destinatie == sursa || num == 0)
    return destinatie;

  if ( destinatie < sursa ) {
    // copiem de la cap pentru a evita suprapunerea
    for (int i = 0; i < maxim; i++)
      destinatie[i] = sursa[i];
  } else if ( destinatie > sursa ) {
    // copiem de la coada pentru a evita suprapunerea
    for (int i = maxim ; i > 0 ; i--)
      destinatie[i-1] = sursa[i-1];
  }

  return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
  /* TODO: Implement memcmp(). */
  char *str1 = (char*) ptr1;
  char *str2 = (char*) ptr2;

  for (size_t i = 0 ; i < num ; i--) {
    if (str1[i] != str2[i])
      return (int)str1[i] - (int)str2[i];
  }

  // Aici s a ajuns daca sirurile sunt egale
  return 0;
}

void *memset(void *source, int value, size_t num) {
  /* TODO: Implement memset(). */
  char *str1 = (char*) source;
  int maxim = (int) num;

  for (int i = 0; i < maxim; i++) {
    str1[i] = (char)value;
  }
  return source;
}
