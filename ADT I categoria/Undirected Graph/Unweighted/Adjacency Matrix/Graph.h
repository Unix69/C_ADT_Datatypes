#ifndef GRAPH_H
#define GRAPH_H

typedef struct { int v; int w; } Edge;
Edge EDGE(int, int);

typedef struct graph *Graph;

Graph GRAPHinit(int);
void  GRAPHinsertE(Graph, Edge);
void  GRAPHremoveE(Graph, Edge);
int   GRAPHedges(Edge [], Graph G);
void  GRAPHshow(Graph G);
Graph GRAPHrand(Graph G, int V, int E);
int   GRAPHpath(Graph G, int v, int w);
int   GRAPHpathH(Graph G, int v, int w);
void  GRAPHbfs(Graph G);

#endif
