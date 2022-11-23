#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"

typedef struct node *link;
struct node { int v; int wt; link next; } ;
struct graph { int V; int E; link *adj; } ;

link NEW(int v, int wt, link next)
  { link x = malloc(sizeof *x);
    x->v = v; x->wt = wt; x->next = next;
    return x;
  }

Edge EDGE(int v, int w, int wt)
{
    Edge e;
    e.v = v;
    e.w = w;
    e.wt = wt;
    return e;
}

Graph GRAPHinit(int V)
{
    int v;
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->E = 0;
    G->adj = malloc( V  * sizeof(link));
    for (v = 0; v < V; v++)
        G->adj[v] = NULL;
    return G;
}

void  GRAPHinsertE(Graph G, Edge e)
{
    int v = e.v, w = e.w, wt = e.wt;
    if (v == w) return;
    G->adj[v] = NEW(w, wt, G->adj[v]);
    G->adj[w] = NEW(v, wt, G->adj[w]);
    G->E++;
}

int   GRAPHedges(Edge a[], Graph G)
{
    int v, E = 0;
    link t;
    for (v=0; v < G->V; v++)
        for (t=G->adj[v]; t != NULL; t = t->next)
            if (v < t->v)
                a[E++] = EDGE(v, t->v, t->wt);
    return E;
}

void  GRAPHshow(Graph G)
{
    int v;
    link t;
    printf("%d vertices, %d edges \n", G->V, G->E);
    for (v=0; v < G->V; v++)
    {
        printf("%2d:", v);
        for (t=G->adj[v]; t != NULL; t = t->next)
            printf("%d/%d \t", t->v, t->wt);
        printf("\n");
    }
}

