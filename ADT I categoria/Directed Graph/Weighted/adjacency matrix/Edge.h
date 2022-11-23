#ifndef EDGE_H_DEFINED
#define EDGE_H_DEFINED

typedef struct Edge_ {
    int v;
    int w;
} Edge;


Edge EDGE(int, int);
void EDGEshow(Edge x);

#define NULLEdge {0}
#define isEdgeNULL(a) (a == 0)

#endif
