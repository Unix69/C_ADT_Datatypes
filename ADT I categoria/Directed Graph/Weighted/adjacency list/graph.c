#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"
#include "PQUEUE.h"
#define maxWT 1000
#define maxV 100

typedef struct node *link;
struct node { int v; int wt; int dist; link next; } ;
struct graph { int V; int E; link *adj; } ;


link NEW(int v, int wt, link next)
{
    link x = malloc(sizeof *x);
    x->v = v;
    x->wt = wt;
    x->next = next;
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
    G->E++;
}

int   GRAPHedges(Edge a[], Graph G)
{
    int v, E = 0;
    link t;
    for (v=0; v < G->V; v++)
        for (t=G->adj[v]; t != NULL; t = t->next)
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

void GRAPHspD(Graph G, int s, int st[], int mindist[])
{
    int v, w; link t;
    PQ pq = PQUEUEinit(G->V);

    for (v = 0; v < G->V; v++)
    {
        st[v] = -1;
        mindist[v] = maxWT;
        PQUEUEinsert(pq, mindist, v);
    }

    mindist[s] = 0;
    st[s] = s;
    PQUEUEchange(pq, mindist, s);

    while (!PQUEUEempty(pq))
    {
        if (mindist[v = PQUEUEextractMin(pq, mindist)] != maxWT)
            for (t=G->adj[v]; t!=NULL ; t=t->next)
                if (mindist[v] + t->wt < mindist[w = t->v])
                {
                    mindist[w] = mindist[v] + t->wt;
                    PQUEUEchange(pq, mindist, w);
                    st[w] = v;
                }
    }
    printf("\n Shortest path tree\n");
    for (v = 0; v < G->V; v++)
        printf("st[%d] = %d \n", v, st[v]);

    printf("\n Minimum distances from node %d\n", s);
    for (v = 0; v < G->V; v++)
        printf("mindist[%d] = %d \n", v, mindist[v]);
}

void GRAPHspBF(Graph G, int s, int st[], int mindist[] )
{
    int v, w, negcycfound;
    link t;
    for ( v = 0; v < G->V; v++);
    {
        st[v]= -1;
        mindist[v] = maxWT;
    }

    mindist[s] = 0;
    st[s] = s;

    for (w = 0; w < G->V - 1; w++)
        for (v = 0; v < G->V; v++)
            if (mindist[v] < maxWT)
                for (t = G->adj[v]; t!=NULL ; t = t->next)
                    if (mindist[t->v] > mindist[v] + t->wt)
                    {
                        mindist[t->v] = mindist[v] + t->wt;
                        st[t->v] = v;
                    }
    negcycfound = 0;
    for (v = 0; v < G->V; v++)
        if (mindist[v] < maxWT)
            for (t = G->adj[v]; t!=NULL ; t = t->next)
                if (mindist[t->v] > mindist[v] + t->wt)
                    negcycfound = 1;
    if (negcycfound == 0)
    {
        printf("\n Shortest path tree\n");
        for (v = 0; v < G->V; v++)
            printf("st[%d] = %d \n", v, st[v]);

        printf("\n Minimum distances from node %d\n", s);
        for (v = 0; v < G->V; v++)
            printf("mindist[%d] = %d \n", v, mindist[v]);
    }
    else
        printf("\n Negative cycle found!\n");
}


