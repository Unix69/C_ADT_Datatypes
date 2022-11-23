#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"
#include "ts.h"

typedef struct graph *Graph;

Graph GRAPHinit(int);
void  GRAPHallsimplepaths(Graph G, TS vertices, int start);
void  GRAPHInsertE(Graph G, int v, int w, int E);
void  GRAPHshow(Graph G, TS vertices);
void  GRAPHfree(Graph G);

#endif
