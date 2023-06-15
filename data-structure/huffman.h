#ifndef HUFFMAN_H_
#define HUFFMAN_H_

typedef struct {
  unsigned int weight;
  unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;

typedef char **HuffmanCode;

#endif // HUFFMAN_H_
