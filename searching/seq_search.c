int SeqSearch(int A[max], int key, int n) {
  int i, flag = 0, position;
  for (i=0; i<n; i++) {
    if (key == A[i]) {
      position = i;
      flag = 1;
      break;
    }
  }

  if (flag == 1) {
    return position;
  }

  return -1;
}

int SeqSearch_sentinel(int A[max], int key, int n) {
  int i, position;
  A[n] = key;
  while (key != A[i]) {
    i++;
  }

  if (i < n) {
    return i;
  }

  return -1;
}
