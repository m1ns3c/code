#include "glist.h"

GLNode* GetHead(GList L) {
  GLNode *p;
  if (!L) {
    return NULL;
  }

  p = L->ptr.hp;
  if (!p) {

  } else if (p->tag == LIST) {

  } else {

  }

  return p;
}

GLNode* GetTail(GList L) {
  if (!L) {
    return NULL;
  }
  return L->ptr.tp;
}

int GListLength(GList L) {
  int len = 0;
  while (L) {
    L = L->ptr.tp;
    len++;
  }
  return len;
}

void CopyList(GList *T, GList L) {
  if (!L) {
    *T = NULL;
  } else {
    *T = (GList)malloc(sizeof(GLNode));
    if (*T == NULL) {
      exit(-1);
    }

    (*T)->tag = L->tag;
    if (L->tag == ATOM) {
      (*T)->atom = L->atom;
    } else {
      CopyList(&((*T)->ptr.hp), L->ptr.hp);
      CopyList(&((*T)->ptr.tp), L->ptr.tp);
    }
  }
}

int GListDepth(GList L) {
  int max, depth;
  GLNode *p;
  if (!L) {
    return 1;
  }

  if (L->tag == ATOM) {
    return 0;
  }

  for (max=0, p=L; p; p=p->ptr.tp) {
    depth = GListDepth(p->ptr.hp);
    if (max < depth) {
      max = depth;
    }
  }
  return max + 1;
}

void DistributeString(SeqString *Str, SeqString *HeadStr) {
  int len, i, k;
  SeqString Ch, Ch1, Ch2, Ch3;
  len = StrLength(*Str);
  StrAssign(&Ch1, ",");
  StrAssign(&Ch2, "(");
  StrAssign(&Ch3, ")");

  SubString(&Ch, *Str, 1, 1);
  for (i=1, k=0; i<len&&StrCompare(Ch, Ch1) || k!=0; i++) {
    SubString(&Ch, *Str, i, 1);
    if (!StrCompare(Ch, Ch2)) {
      k++;
    } else if (!StrCompare(Ch, Ch3)) {
      k--;
    }
  }
  if (i<=len) {
    SubString(HeadStr, *Str, 1, i-2);
    SubString(Str, *Str, i, len-i+1);
  } else {
    StrCopy(HeadStr, *Str);
    StrClear(Str);
  }
}

void CreateList(GList *L, SeqString S) {
  SeqString Sub, HeadSub, Empty;
  GList p, q;
  StrAssign(&Empty, "()");

  if (!StrCompare(S, Empty)) {
    *L = NULL;
  } else {
    *L = (GList)malloc(sizeof(GLNode));
    if (!L) {
      exit(-1);
    }

    if (StrLength(S) == 1) {
      (*L)->tag = ATOM;
      (*L)->atom = S.str[0];
    } else {
      (*L)->tag = LIST;
      p = *L;
      SubString(&Sub, S, 2, StrLength(S)-2);
      do {
        DistributeString(&Sub, &HeadSub);
        CreateList(&(p->ptr.hp), HeadSub);
        q = p;
        if (!StrEmpty(Sub)) {
          if (!(p = (GLNode *)malloc(sizeof(GLNode)))) {
            eixt(-1);
          }
          p->tag = LIST;
          q->ptr.tp = p;
        }
      } while (!StrEmpty(Sub));
      q->ptr.tp=NULL;
    }
  }
}

void PrintGList(GList L) {
  if (L) {
    if (L->tag == ATOM) {
      printf("%c ", L->atom);
    } else {
      PrintGList(L->ptr.hp);
      PrintGList(L->ptr.hp);
    }
  }
}
