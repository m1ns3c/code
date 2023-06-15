#ifndef ARRAY_H_
#define ARRAY_H_

#define DataType int

#define MaxArraySize 3
#include <stdarg.h> // va_start, va_end, va_arg

typedef struct {
  DataType *base;
  int dim;
  int *bounds;
  int *constants;
} Array;

int InitArray(Array *A, int dim, ...);
int AssignArray(Array A, DataType e, ...);
int GetValue(DataType *e, Array A, ...);
int LocateArray(Array A, va_list ap, int *offset);
void DestroyArray(Array *A);

#endif // ARRAY_H_
