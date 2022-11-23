#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"
#include "UF.h"

struct graph {int V; int E; int **adj; };
static Edge mst[maxE];
static int E;
static int fr[maxV];

Edge EDGE(int v, int w, int wt)
{
    Edge e;
    e.v = v;
    e.w = w;
    e.wt = wt;
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
    G->adj = MATRIXint(V, V, maxWT);
    return G;
}

void  GRAPHinsertE(Graph G, Edge e)
{
    int v = e.v, w = e.w, wt = e.wt;
    if (G->adj[v][w] == 0)
        G->E++;
    G->adj[v][w] = wt;
    G->adj[w][v] = wt;
}


void  GRAPHremoveE(Graph G, Edge e)
{
    int v = e.v, w = e.w;
    if (G->adj[v][w] != 0)
        G->E--;
    G->adj[v][w] = 0;
    G->adj[w][v] = 0;
}

int   GRAPHedges(Edge a[], Graph G)
{
    int v, w, E = 0;
    for (v=0; v < G->V; v++)
        for (w=v+1; w < G->V; w++)
            if (G->adj[v][w] != 0)
                a[E++] = EDGE(v, w, G->adj[v][w]);
    return E;
}

void  GRAPHshow(Graph G)
{
    int i, j;
    printf("%d vertices, %d edges \n", G->V, G->E);
    for (i=0; i < G->V; i++)
    {
        printf("%2d:", i);
        for (j=0; j < G->V; j++)
            printf("%2d", G->adj[i][j]);
        printf("\n");
    }
}
void sort(Edge a[], int l, int r )
{
	int i, j, min, temp;
	for(i = l; i < r; i++)
	{
		min = i;
		for (j = i+1; j <= r; j++)
			if (a[j].wt < a[min].wt)
                min = j;
		temp = a[i].v;
		a[i].v = a[min].v;
		a[min].v = temp;

		temp = a[i].w;
		a[i].w = a[min].w;
		a[min].w = temp;

		temp = a[i].wt;
		a[i].wt = a[min].wt;
		a[min].wt = temp;
	}
	return;
}

int GRAPHmstE(Graph G, Edge mst[])
{
    int i, k;
    Edge a[maxE];
    E = GRAPHedges(a, G);


    sort(a, 0, E-1);

    UFinit(G->V);

    for ( i=0, k=0; i < E && k < G->V-1; i++ )
        if (!UFfind(a[i].v, a[i].w))
        {
            UFunion(a[i].v, a[i].w);
            mst[k++] = a[i];
        }
    return k;
}

void GRAPHmstK(Graph G)
{
    int i, k, weight = 0;

    k = GRAPHmstE(G, mst);

    printf("\n The list of edges in the MST is: \n");

    for (i=0; i < k; i++)
    {
        printf("(%d - %d) \n", mst[i].v, mst[i].w);
        weight += mst[i].wt;
    }
    printf("minimum weight: %d\n", weight);
}

void GRAPHmstV(Graph G, int st[], int wt[])
{
    int v, w, min;
    for ( v=0; v < G->V; v++)
    {
        st[v] = -1;
        fr[v] = v;
        wt[v] = maxWT;
    }
    st[0] = 0;
    wt[0] = 0;
    wt[G->V] = maxWT;

    for ( min = 0; min != G->V; )
    {
        v = min;
        st[min] = fr[min];
        for (w = 0, min = G->V; w < G->V; w++)
            if (st[w] == -1)
            {
                if (G->adj[v][w] < wt[w])
                {
                    wt[w] = G->adj[v][w];
                    fr[w] = v;
                }
                if (wt[w] < wt[min])
                    min = w;
            }
    }
}

void GRAPHmstP(Graph G)
{
    int v, st[maxV], wt[maxV];

    GRAPHmstV(G, st, wt);
    printf("st \n");
    for ( v=0; v < G->V; v++)
        printf("%5d", v);
    printf("\n");

    for ( v=0; v < G->V; v++)
        printf("%5d", st[v]);
    printf("\n");

    printf("wt \n");

    for ( v=0; v < G->V; v++)
        printf("%5d", wt[v]);
    printf("\n");
}
