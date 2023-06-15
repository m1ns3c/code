#ifndef LINKSTRING_H_
#define LINKSTRING_H_

#define ChunkSize 10
#define stuff '#

typedef struct Chunk {
  char ch[ChunkSize];
  struct Chunk *next;
}Chunk;

typedef struct {
  Chunk *head;
  Chunk *tail;
  int length;
} LinkString;


void InitString(LinkString *S);
int StrAssign(LinkString *S, char *cstr);
int ToChars(LinkString S, char **cstr);
int StrCompare(LinkString S, LinkString T);
int StrInsert(LinkString *S, int pos, LinkString T);
int StrDelete(LinkString *S, int pos, int len);
void ClearString(LinkString *S);

#endif // LINKSTRING_H_
