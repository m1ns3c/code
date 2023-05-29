#include <stdio.h>

#define MaxLen 100

typedef struct {
  char str[MaxLen];
  int len;
}SeqString;

void StrAssign(SeqString *S, char cstr[]) {
  int i;
  for (i=0; cstr[i] !='\0'; i++) {
    S->str[i] = cstr[i];
  }
  S->len = i;
}

int StrIndex(SeqString S, SeqString R) {
  return 0;
}

int StrReplace(SeqString *S, int pos, SeqString R) {
  return 0;
}

int main() {
  int pos;
  SeqString S, R;
  char str[] = "abcdeabdbcdaaabdecdf";
  char str_r[] = "abd";

  StrAssign(&S, str);
  StrAssign(&R, str_r);

  while ((pos = StrIndex(S, R)) >= 0) {
    StrReplace(&S, pos, R);
  }

  return 0;
}
