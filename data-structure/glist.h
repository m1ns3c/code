#ifndef GLIST_H_
#define GLIST_H_

typedef enum{ATOM, LIST} ElemTag;

typedef struct {
  ElemTag tag;
  union {
    AtomType atom;
    struct {
      struct GLNode *hp, *tp;
    }ptr;
  };
}GLNode, *GList;

GLNode* GetHead(GList L);
GLNode* GetTail(GList L);
int GListLength(GList L);
void CopyList(GList *T, GList L);
int GListDepth(GList L);

#endif // GLIST_H_
