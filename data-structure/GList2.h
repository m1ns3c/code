#ifndef GLIST2_H_
#define GLIST2_H_

typedef enum {ATOM,LIST} ElemTag;

typedef struct {
  ElemTag tag;
  union {
    AtomType atom;
    struct GLNode *hp;
  } ptr;
  struct GLNode *tp;
}GLNode, *GList;

#endif // GLIST2_H_
