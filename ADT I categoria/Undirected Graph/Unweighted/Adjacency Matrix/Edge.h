#ifndef EDGE_H_DEFINED
#define EDGE_H_DEFINED

#define less(A, B) (key(A) < key(B))
#define greater(A, B) (key(A) > key(B))
#define MAX 10

typedef struct { int x; int y; } Edge;
typedef int Key;

Key key(Edge x);
void EDGEshow(Edge x);

#endif
