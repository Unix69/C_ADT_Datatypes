#ifndef GRAPH_H
#define GRAPH_H

typedef struct { int v; int w; } Edge;
Edge EDGE(int, int);

typedef struct graph *Graph;

Graph GRAPHinit(int);
void  GRAPHinsertE(Graph, Edge);
void  GRAPHremoveE(Graph, Edge);
int   GRAPHedges(Graph G, Edge []);
void  GRAPHshow(Graph G);
Graph GRAPHrand(Graph G, int, int);
void  GRAPHdfs(Graph G);
void  GRAPHbridge(Graph G);
int   GRAPHcc(Graph G);
int   GRAPHconnect (Graph G, int, int);

#endif
