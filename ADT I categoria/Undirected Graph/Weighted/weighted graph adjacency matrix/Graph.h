#ifndef GRAPH_H
#define GRAPH_H

#define maxV 20
#define maxE maxV*(maxV-1)/2
#define maxWT 1000

typedef struct { int v; int w; int wt;} Edge;
Edge EDGE(int, int, int);

typedef struct graph *Graph;

Graph GRAPHinit(int);
void  GRAPHinsertE(Graph, Edge);
void  GRAPHremoveE(Graph, Edge);
int   GRAPHedges(Edge [], Graph G);
void  GRAPHshow(Graph G);
int   GRAPHmstE(Graph G, Edge mst[]);
void  GRAPHmstK(Graph G);
void  GRAPHmstP(Graph G);

#endif


