#include <stdio.h>
#include <string.h>

#define MaxSize 50

void getNextVal(char t[], int n[]) {
  int len = strlen(t);
  int i = 1, j = 0;
  n[i] = n[j] = 0;
  while (i < n) {
    if (j == 0 || t[i] == t[j]) {

    } else {
      j = next[j];
    }
  }
}

void getNext(char t[], int n[]) {
  int len = strlen(t);
  int i = 0, j = 0;
  n[i++] = 0;

  for (; i<len; i++) {
    while (j > 0 && t[i] != t[j]) {
      j = n[j - 1];
    }

    if (t[i] == t[j]) {
      j++;
    }

    n[i] = j;
  }
}

int KMP(char s[], char t[]) {
  int n[MaxSize];
  getNext(t, n);

  int i, j, len_s = strlen(s), len_t = strlen(t);

  for (i=0, j=0; i<len_s; i++) {
    while (j > 0 && s[i] != t[j]) {
      j = n[j - 1];
    }

    if (s[i] == t[j]) {
      j++;
    }

    if (len_t == j) {
      return i - j + 1;
    }
  }

  return -1;
}

int main() {
  char s[] = "1231234123123512";
  char t[] = "1235";

  printf("%s\n%s\n%d\n", s, t, KMP(s, t));

  return 0;
}
