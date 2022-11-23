#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"
#define maxV 100

typedef struct node *link;
struct node { int v; link next; } ;
struct graph { int V; int E; link *adj; int *cc; } ;

static int time, pre[maxV], post[maxV], st[maxV], bcnt, low[maxV];

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

Graph GRAPHinit(int V)
{
    int v;
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->E = 0;
    G->adj = malloc(G->V*sizeof(link));
    for (v = 0; v < G->V; v++)
        G->adj[v] = NULL;
    return G;
}

void  GRAPHinsertE(Graph G, Edge e)
{
    int v = e.v, w = e.w;

    G->adj[v] = NEW(w, G->adj[v]);
    G->adj[w] = NEW(v, G->adj[w]);
    G->E++;
}

int   GRAPHedges(Graph G, Edge a[])
{
    int v, E = 0;
    link t;
    for (v=0; v < G->V; v++)
        for (t=G->adj[v]; t != NULL; t = t->next)
            if (v < t->v)
                a[E++] = EDGE(v, t->v);
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
            printf("%2d  ", t->v);
        printf("\n");
    }
}

int randV(Graph G)
{
    return G->V * (rand() / (RAND_MAX + 1.0));
}

/* random edges

Graph GRAPHrand(Graph G, int V, int E)
{
    while (G->E < E)
       GRAPHinsertE(G, EDGE(randV(G), randV(G)));
    return G;
}
*/

// edges with probability p
Graph GRAPHrand(Graph G, int V, int E)
{
    int i, j;
    double p = 2.0 * E / (V * (V-1));
    for ( i = 0; i < V; i++)
        for ( j = i+1; j < V; j++)
            if (rand() < p * RAND_MAX)
                GRAPHinsertE(G, EDGE(i, j));
    return G;
}

void dfsR(Graph G, Edge e)
{
    link t; int v, w = e.w; Edge x;
    if (e.v != e.w)
        printf("edge (%d, %d) is tree \n", e.v, e.w) ;
    st[e.w] = e.v;
    pre[w] = time++;
    for (t = G->adj[w]; t != NULL; t = t->next)
      if (pre[t->v] == -1)
        dfsR(G, EDGE(w, t->v));
      else {
        v = t->v;
        x = EDGE(w, v);
        if (pre[w] < pre[v])
            printf("edge (%d, %d) is back \n", x.v, x.w) ;
      }
    post[w] = time++;
}

void bridgeR(Graph G, Edge e)
{
    link t;
    int v, w = e.w;
    pre[w] = time++;
    low[w] = pre[w];
    for (t = G->adj[w]; t != NULL; t = t->next)
        if (pre[v = t->v] == -1)
        {
            bridgeR(G, EDGE(w, v));
            if (low[w] > low[v])
                low[w] = low[v];
            if (low[v] == pre[v])
            {
                bcnt++;
                printf("edge %d - %d is a bridge \n", w, v);
            }
        }
        else if (v != e.v)
            if(low[w] > pre[v])
                low[w] = pre[v];
}

void GRAPHdfs(Graph G)
{
    int v;
    time = 0;
    for (v=0; v < G->V; v++)
    {
      pre[v] = -1;
      post[v] = -1;
      st[v] =  -1;
    }
    for (v=0; v < G->V; v++)
      if (pre[v]== -1)
        dfsR(G, EDGE(v,v));

    printf("discovery/endprocessing time labels \n");
    for (v=0; v < G->V; v++)
        printf("vertex %d : %d/%d \n", v, pre[v], post[v]);

    printf("resulting DFS tree \n");
    for (v=0; v < G->V; v++)
        printf("parent of vertex %d is vertex  %d \n", v, st[v]);

}
void  GRAPHbridge(Graph G)
{
    int v;
    time = 0, bcnt =0;
    for (v=0; v < G->V; v++)
      pre[v] = -1;
    for (v=0; v < G->V; v++)
      if (pre[v]== -1)
        bridgeR(G, EDGE(v, v));
    if (bcnt == 0)
      printf("No bridge found!\n");
}

void dfsRcc(Graph G, int v, int id)
{
     link t;
     G->cc[v] = id;
     for (t = G->adj[v]; t != NULL; t = t->next)
         if (G->cc[t->v] == -1) dfsRcc(G, t->v, id);
}
int GRAPHcc(Graph G)
{
    int v, id = 0;
    G->cc = malloc(G->V * sizeof(int));
    for (v = 0; v < G->V; v++)
        G->cc[v] = -1;
    for (v = 0; v < G->V; v++)
        if (G->cc[v] == -1) dfsRcc(G, v, id++);
    printf("Connected component(s) \n");
    for (v = 0; v < G->V; v++)
        printf("node %d belongs to cc %d \n", v, G->cc[v]);
    return id;
}

int GRAPHconnect(Graph G, int s, int t)
{
    return G->cc[s] == G->cc[t];
}

