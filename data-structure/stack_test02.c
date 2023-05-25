#include <stdio.h>
#include "linkstack.h"

int main() {
  char s[] = "6 7 1 - 3 * + 10 2 / +";
  char *c = s;
  int n = 0, t;
  DataType e;

  LinkStack S;
  InitStack(&S);

  while (*c != '\0') {
    if (*c != ' ' && *c >= '0' && *c <= '9') {
      n = n*10 + (*c) - '0';
    } else if (*c == ' ') {
      if (n != 0) {
        PushStack(&S, n);
        //printf("%d\n", n);
      }
      n = 0;
    } else {
      DataType e1, e2;
      PopStack(&S, &e1);
      PopStack(&S, &e2);

      switch (*c) {
        case '+':
          t = e2 + e1;
          break;
        case '-':
          t = e2 - e1;
          break;
        case '*':
          t = e2 * e1;
          break;
        case '/':
          t = e2 / e1;
          break;
      }

      PushStack(&S, t);
    }
    c++;
  }

  PopStack(&S, &e);

  printf("%d\n", e);

  return 0;
}
