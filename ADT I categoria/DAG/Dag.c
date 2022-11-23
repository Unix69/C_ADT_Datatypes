#include <stdlib.h>
#include <stdio.h>
#include "Dag.h"
#define maxV 20

typedef struct node *link;
struct node { int v; link next; } ;
struct dag { int V; int E; link *adj; } ;

static int time, pre[maxV], ts[maxV];

link NEW(int v, link next)
  { link x = malloc(sizeof *x);
    x->v = v; x->next = next;
    return x;
  }

Edge EDGE(int v, int w)
{
    Edge e;
    e.v = v;
    e.w = w;
    return e;
}

Dag DAGinit(int V)
{
    int v;
    Dag D = malloc(sizeof *D);
    D->V = V;
    D->E = 0;
    D->adj = malloc( V  * sizeof(link));
    for (v = 0; v < V; v++)
        D->adj[v] = NULL;
    return D;
}

void  DAGinsertE(Dag D, Edge e)
{
    int v = e.v, w = e.w;

    D->adj[v] = NEW(w, D->adj[v]);
    D->E++;
}

int   DAGedges(Edge a[], Dag D)
{
    int v, E = 0;
    link t;
    for (v=0; v < D->V; v++)
        for (t=D->adj[v]; t != NULL; t = t->next)
            if (v < t->v)
                a[E++] = EDGE(v, t->v);
    return E;
}

void  DAGshow(Dag D)
{
    int v;
    link t;
    printf("%d vertices, %d edges \n", D->V, D->E);
    for (v=0; v < D->V; v++)
    {
        printf("%3d:", v);
        for (t=D->adj[v]; t != NULL; t = t->next)
            printf("%3d", t->v);
        printf("\n");
    }
}


void TSdfsR(Dag D, int v, int ts[])
{ link t;
  pre[v] = 0;
  for (t = D->adj[v]; t != NULL; t = t->next)
    if (pre[t->v] == -1)
      TSdfsR(D, t->v, ts);
  ts[time++] = v;
}

void DAGrts(Dag D)
  {
    int v;
    time = 0;
    for (v=0; v < D->V; v++)
    {
        pre[v] = -1;
        ts[v] = -1;
    }
    for (v=0; v < D->V; v++)
        if (pre[v]== -1)
            TSdfsR(D, v, ts);

    printf("DAG nodes in reverse topological order \n");
    for (v=0; v < D->V; v++)
        printf("%d  ", ts[v]);
    printf("\n");

  }


