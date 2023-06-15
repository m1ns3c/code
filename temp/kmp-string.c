#include <stdio.h>
#include <string.h>

#define MaxSize 50

void getNext(char t[], int arr[]) {
  int i = 0, j = 0;
  arr[i++] = 0;
  int len = strlen(t);

  for (;i<len;i++) {
    while (j > 0 && t[i] != t[j]) {
      j = arr[j-1];
    }
    if (t[i] == t[j]) {
      j++;
    }
    arr[i] = j;
  }
}

int KMP(char s[], char t[]) {
  int n[MaxSize];
  getNext(t, n);

  int len1 = strlen(s);
  int len2 = strlen(t);
  int i = 0, j = 0;

  for(; i< len1; i++) {
    while (s[i] != t[j] && j > 0) {
      j = n[j - 1];
    }

    if (s[i] == t[j]) {
      j++;
    }

    if (len2 == j) {
      return i - j + 1;
    }
  }

  return -1;
}

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
  char pattern[] = "aaf";

  int pos = bp(str, pattern);
  printf("%d\n", pos);
  pos = KMP(str, pattern);
  printf("%d\n", pos);

  return 0;
}
