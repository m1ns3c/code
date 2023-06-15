#include "array.h"
#include <stdlib.h>

int InitArray(Array *A, int dim, ...) {
  int elemtotal = 1, i;
  va_list ap;
  if (dim < 1 || dim > MaxArraySize) {
    return 0;
  }
  A->dim = dim;
  A->bounds = (int *) malloc(dim*sizeof(int));
  if (!A->bounds) {
    exit(-1);
  }

  va_start(ap, dim);
  for (i=0; i<dim; i++) {
    A->bounds[i] = va_arg(ap, int);
    if (A->bounds[i] < 0) {
      return -1;
    }
    elemtotal *= A->bounds[i];
  }
  va_end(ap);
  A->base = (DataType *) malloc(elemtotal * sizeof(DataType));
  if (!A->base) {
    exit(-1);
  }

  A->constants = (int *)malloc(dim * sizeof(int));
  if (!A->constants) {
    exit(-1);
  }
  A->constants[dim - 1] = 1;
  for (i=dim - 2; i>=0; i--) {
    A->constants[i] = A->bounds[i+1] * A->constants[i+1];
  }

  return 1;
}

int AssignArray(Array A, DataType e, ...) {
  va_list ap;
  int offset;
  va_start(ap, e);
  if (LocateArray(A, ap, &offset) == 0) {
    return 0;
  }
  va_end(ap);
  *(A.base+offset) = e;
  return 1;
}

int GetValue(DataType *e, Array A, ...) {
  va_list ap;
  int offset;
  va_start(ap, A);
  if (LocateArray(A, ap, &offset) == 0) {
    return 0;
  }
  va_end(ap);
  *e = *(A.base + offset);
  return 1;
}

int LocateArray(Array A, va_list ap, int *offset) {
  int i, instand;
  *offset = 0;
  for (i=0; i<A.dim; i++) {
    instand = va_arg(ap, int);
    if (instand<0 || instand >= A.bounds[i]) {
      return 0;
    }
    *offset += A.constants[i] * instand;
  }
  return 1;
}

void DestroyArray(Array *A) {
  if (A->base) {
    free(A->base);
  }

  if (A->bounds) {
    free(A->bounds);
  }

  if (A->constants) {
    free(A->constants);
  }

  A->base = A->bounds = A->constants = NULL;
  A->dim = 0;
}
