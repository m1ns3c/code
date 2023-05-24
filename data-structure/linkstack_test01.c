#include "linkstack.h"

int main() {
  LinkStack S;
  int n = 5678, r;

  InitStack(&S);

  while (n) {
    r = n % 8;

    PushStack(&S, r);

    n = n / 8;
  }

  PrintStack(S);

  return 0;
}
