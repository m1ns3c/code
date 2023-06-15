#include "linkstring.h"

void InitString(LinkString *S) {
  S->head = S->tail = NULL;
  S->length = 0;
}

int StrAssign(LinkString *S, char *cstr) {
  int i, j, len;
  Chunk *p, *q;
  len = strlen(cstr);
  if (!len) {
    return 0;
  }

  S->length = len;
  j = len / ChunkSize;
  if (len % ChunkSize) {
    j++;
  }

  for (i=0; i<j; i++) {
    p = (Chunk *)malloc(sizeof(Chunk));
    if (!p) {
      return 0;
    }
    for (k=0; k<ChunkSize && *cstr; k++) {
      *(p->ch + k) = *cstr++;
    }
    if (i == 0) {
      S->head = q = p;
    } else {
      q->next = p;
      q = p;
    }

    if (!*cstr) {
      S->tail = q;
      q->next = NULL;
      for (; k<ChunkSize; k++) {
        *(q->ch+k) = stuff;
      }
    }
  }

  return 1;
}

int ToChars(LinkString S, char **cstr) {
  Chunk *p = S.head;
  int i;
  char *q;
  *cstr = (char *)malloc((S.length+1)*sizeof(char));
  if (!cstr || !S.length) {
    return 0;
  }
  q = *cstr;

  while (p) {
    for (i=0;i<ChunkSize;i++) {
      if (p->ch[i] != stuff) {
        *q++ = (p->ch[i]);
      }
    }
    p = p->next;
  }

  (*cstr)[S.length] = '\0';

  return 1;
}

int StrCompare(LinkString S, LinkString T) {
  return 1;
}

int StrInsert(LinkString *S, int pos, LinkString T) {
  return 1;
}

int StrDelete(LinkString *S, int pos, int len) {
  return 1;
}

void ClearString(LinkString *S) {
  Chunk *p, *q;
  p = S->head;
  while (p) {
    q = p->next;
    free(p);
    p = q;
  }
  S->head = S->tail = NULL;
  S->length = 0;
}
