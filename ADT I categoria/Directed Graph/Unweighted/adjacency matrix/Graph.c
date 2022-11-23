#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"
#include "Queue.h"
#define maxV 100

struct graph {int V; int E; int **adj; int *visited; };

static int time, pre[maxV], st[maxV];

Edge EDGE(int v, int w)
{
    Edge e;
    e.v = v;
    e.w = w;
    return e;
}
int **MATRIXint(int r, int c, int val)
{
    int i, j;
    int **t = malloc(r * sizeof(int *));
    for (i=0; i < r; i++)
        t[i] = malloc(c * sizeof(int));
    for (i=0; i < r; i++)
        for (j=0; j < c; j++)
            t[i][j] = val;
    return t;
}

Graph GRAPHinit(int V)
{
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->E = 0;
    G->adj = MATRIXint(V, V, 0);
    G->visited = malloc(G->V * sizeof(int));
    return G;
}

void  GRAPHinsertE(Graph G, Edge e)
{
    int v = e.v, w = e.w;
    if (G->adj[v][w] == 0)
        G->E++;
    G->adj[v][w] = 1;
}

void  GRAPHremoveE(Graph G, Edge e)
{
    int v = e.v, w = e.w;
    if (G->adj[v][w] == 1)
        G->E--;
    G->adj[v][w] = 0;
}

int   GRAPHedges(Edge a[], Graph G)
{
    int v, w, E = 0;
    for (v=0; v < G->V; v++)
        for (w=0; w < G->V; w++)
            if (G->adj[v][w] == 1)
                a[E++] = EDGE(v, w);
    return E;
}

void  GRAPHshow(Graph G)
{
    int i, j;
    printf("Graph has %d vertices, %d edges \n", G->V, G->E);
    for (i=0; i < G->V; i++)
    {
        printf("%2d:", i);
        for (j=0; j < G->V; j++)
            printf("%2d", G->adj[i][j]);
        printf("\n");
    }
}

int randV(Graph G)
{
    return G->V * (rand() / (RAND_MAX + 1.0));
}

/* random edges

Graph GRAPHrand(int V, int E)
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

int pathR(Graph G, int v, int w)
{
    int t;
    if (v == w)
        return 1;
    G->visited[v] = 1;
    for ( t = 0 ; t < G->V ; t++)
        if (G->adj[v][t] == 1)
            if (G->visited[t] == 0)
                if (pathR(G, t, w))
                {
                    printf("edge (%d, %d) belongs to path \n", v, t);
                    return 1;
                }
     return 0;
}

int GRAPHpath(Graph G, int v, int w)
{
    int t, found;
    for ( t = 0 ; t < G->V ; t++)
        G->visited[t] = 0;
    found = pathR(G, v, w);
    if (found == 0)
        printf("\n Path not found!\n");
    return found;
}

void bfs(Graph G, Edge e)
{
    int v;
    Q q = QUEUEinit();
    QUEUEput(q, e);
    while (!QUEUEempty(q))
        if (pre[(e = QUEUEget(q)).w] == -1)
        {
            pre[e.w] = time++;
            st[e.w] = e.v;
            for (v = 0; v < G->V; v++)
                if (G->adj[e.w][v] == 1)
                    if (pre[v] == -1)
                        QUEUEput(q, EDGE(e.w, v));
        }
}

void GRAPHbfs(Graph G)
{
    int v;
    time = 0;
    for (v=0; v < G->V; v++)
    {
      pre[v] = -1;
      st[v] = -1;
    }
    bfs(G, EDGE(0,0));


    printf("\n Resulting BFS tree \n");
    for (v=0; v < G->V; v++)
        printf("Parent of vertex %d is vertex  %d\n", v, st[v]);
}
