#include "seqstring.h"

void GetNext(SeqString T, int next[]) {
  int j =0 , k = -1;
  next[0] = -1;

  while (j < T.length) {
    if (k == -1 || T.str[j] == T.str[k]) {
      j++;
      k++;
      next[j] = k;
    } else {
      k = next[k];
    }
  }
}

void GetNextVal(SeqString T, int nextval[]) {
  int j = 0, k = -1;
  nextval[0] = -1;

  while (j < T.length) {
    if (k == -1 || T.str[j] == T.str[k]) {
      j++;
      k++;
      if (T.str[j] != T.str[k]) {
        nextval[j] = k;
      } else {
        nextval[j] = nextval[k];
      }
    } else {
      k = nextval[k];
    }
  }
}
