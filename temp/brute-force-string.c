#include <stdio.h>
#include <string.h>

int bp(char *str, char *pattern) {
  int i = 0, j = 0;
  int len1 = strlen(str);
  int len2 = strlen(pattern);

  while (i < len1) {
    if (str[i] == pattern[j]) {
      i++;
      j++;
    } else if (j >= len2) {
      return i - j;
    } else {
      i = i - j + 1;
      j = 0;
    }
  }

  return -1;
}

int main() {
  char str[] = "aabaabaafa";
  char pattern[] = "aab";

  int pos = bp(str, pattern);

  printf("%d\n", pos);

  return 0;
}
