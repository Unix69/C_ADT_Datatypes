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
Graph GRAPHreverse(Graph G);
int GRAPHscc(Graph G);
int GRAPHstrongconnect(Graph G, int s, int t);
#endif
