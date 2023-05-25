#include "linkstack.h"
#include<stdio.h>

#define MaxSize 50

char operators[2][7] = {
  {'+','-',')', '#', '\0'}, // + -
  {'+','-','*','/',')','#', '\0'}, // * / )
};

int in(char ops[], DataType e) {
  char c;
  int i = 0;
  while ((c = ops[i++]) != '\0') {
    if (e == c) {
      return 1;
    }
  }

  return -1;
}

int op(DataType e1, DataType e2) {
  if (e1 == '(' && e2 == ')' || e1 == '#' && e2 == '#')
    return 0;

  switch (e1) {
    case '+':
    case '-':
      return in(operators[0], e2);
    case '*':
    case '/':
    case ')':
      return in(operators[1], e2);
  }

  return -1;
}

void Cmp(LinkStack S, DataType e2, char s2[], int *j) {
  DataType e1;
  while (1) {
    if (EmptyStack(S)) {
      PushStack(&S, e2);
      break;
    }

    if (GetTop(S, &e1) == 0) {
      break;
    }

    int result = op(e1, e2);
    if (result > 0) {
      PopStack(&S, &e1);
      //printf("%c\n", e1);
      s2[(*j)++] = ' ';
      s2[(*j)++] = e1;
    } else if (result < 0) {
      PushStack(&S, e2);
      break;
    } else {
      PopStack(&S, &e1);
      break;
    }
  }
}

void TransExpr(char s1[], char s2[]) {
  int i = 0, j = 0;
  LinkStack S;

  InitStack(&S);

  char c;
  int flag = 0;
  while (c = s1[i]){
    if (c >= '0' && c <= '9') {
      if (flag) {
        s2[j++] = ' ';
      }
      flag = 0;

      s2[j++] = c;
    } else {
      flag = 1;
      Cmp(S, c, s2, &j);
    }
    i++;
  }
}

int main() {
  char s1[] = "6+(7-1)*3+10/2#";
  char s2[MaxSize];

  TransExpr(s1, s2);

  printf("%s\n", s2);

  return 0;
}
