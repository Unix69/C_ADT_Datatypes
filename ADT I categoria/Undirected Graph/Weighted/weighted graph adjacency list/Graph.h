#ifndef GRAPH_H
#define GRAPH_H

typedef struct { int v; int w; int wt;} Edge;
Edge EDGE(int, int, int);

typedef struct graph *Graph;

Graph GRAPHinit(int);
void  GRAPHinsertE(Graph, Edge);
int   GRAPHedges(Edge [], Graph G);
void  GRAPHshow(Graph G);

#endif
