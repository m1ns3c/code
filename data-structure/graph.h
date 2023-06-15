#ifndef GRAPH_H_
#define GRAPH_H_

#define INFINITY 65535
#define MaxSize 50

typedef enum{DG,UG,DN,UN}GraphKind;

typedef struct {
  VRType adj;
  InfoPtr *info;
} ArcNode, AdjMatrix[MaxSize][MaxSize];

typedef struct {
  VertexType vex[MaxSize];
  AdjMatrix arc;
  int vexnum;
  int arcnum;
  GraphKind kind;
}MGraph;

// adjacency list
typedef struct ArcNode {
  int adjvex;
  InfoPtr *info;
  struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode {
  VertexType data;
  ArcNode *firstarc;
}VNode, AdjList[MaxSize];

typedef struct {
  AdjList vertex;
  int vexnum;
  int arcnum;
  GraphKind kind;
}AdjGraph;

// orthogonal list
typedef struct ArcNode {
  int headvex;
  int tailvex;
  InfoPtr *info;
  struct ArcNode *hlink;
  struct ArcNode *tlink;
} ArcNode;

typedef struct VNode {
  VertexType data;
  ArcNode *firstin;
  ArcNode *firstout;
}VNode;

typedef struct {
  VNode vertex[MaxSize];
  int vexnum;
  int arcnum;
}OLGraph;

// adjacency multilist
typedef struct EdgeNode {
  int mark;
  int ivex;
  int jvex;
  InfoPtr *info;
  struct *ilink;
  struct *jlink;
}EdgeNode;

typedef struct VNode {
  VertexType data;
  EdgeNode *firstedge;
}VexNode;

typedef struct {
  VexNode vertex[MaxSize];
  int vexnum;
  int edgenum;
}AdjMultiGraph;

#endif // GRAPH_H_
