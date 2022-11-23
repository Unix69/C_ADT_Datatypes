#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Graph.h"

struct graph {
    int V, E;
    int **adj;
    int time;
    int *visited;
    int *pre;
    int *post;
    int *st;
};

int NULLEdgeWeight = NULLEdge;

int **MATRIXinit(int r, int c, int val)
{
    int i, j;
    int **t = (int **) malloc(r * sizeof(int *));
    if (t == NULL) {
        printf("Errore di allocazione della memoria\n");
        exit(-1);
    }
    for (i=0; i < r; i++)
        t[i] = (int *) malloc(c * sizeof(int));
    for (i=0; i < r; i++)
        for (j=0; j < c; j++)
            t[i][j] = val;
    return t;
}

Graph GRAPHinit(int V)
{
    Graph G = malloc(sizeof(*G));
    if (G == NULL) {
      printf("Errore di allocazione della memoria\n");
      exit(-1);
    }

    G->V = V;
    G->E = 0;
    G->time = 0;

    G->adj = MATRIXinit(V, V, NULLEdgeWeight);
    G->visited = NULL;
    G->pre = NULL;
    G->post = NULL;
    G->st = NULL;

    return G;
}

void  GRAPHshow(Graph G, TS vertices)
{
    int i, j;
    printf("Graph has %d vertices, %d edges \n", G->V, G->E);
    for (i=0; i < G->V; i++)
    {
        printf("%s: ", TSleggiIndice(vertices, i));
        for (j=0; j < G->V; j++)
            printf("%2d", G->adj[i][j]);
        printf("\n");
    }
}

void GRAPHInsertE(Graph G, int v, int w, int E) {
    if (v >= G->V || w >= G->V)
        return;
    if (isEdgeNULL(G->adj[v][w]))
        G->E++;
    G->adj[v][w] = E;
}

static void INITvisit(Graph G) {
    int v;

    G->visited = malloc (G->V * sizeof(int));
    G->pre = malloc (G->V * sizeof(int));
    G->post = malloc (G->V * sizeof(int));
    G->st = malloc (G->V * sizeof(int));

    G->time = 0;
    for (v=0; v < G->V; v++)
    {
        G->pre[v] = -1;
        G->post[v] = -1;
        G->visited[v] = 0;
        G->st[v] = v;
    }
}

static void CLEANvisit(Graph G) {
    free(G->pre);
    free(G->post);
    free(G->visited);
    free(G->st);
}

void GRAPHfree(Graph G) {
    int v;
    for (v=0; v < G->V; v++) {
        free(G->adj[v]);
    }
    free(G->adj);
    free(G);
}

static void pathR(Graph G, TS vertices, Edge e, int len)
{
    int v, end=1;

    G->visited[e.w] = 1;
    if ((G->visited[e.w] ==1) && (e.v != e.w))
        G->st[e.v] = e.w;
    for (v = 0; v < G->V; v++) {
        if (!isEdgeNULL(G->adj[e.w][v]))
            if (G->visited[v] == 0) {
                pathR(G, vertices, EDGE(e.w, v),len+1);
            }
    }
    G->visited[e.w] = 0;

    for (v = 0; v < G->V; v++)
        if (!isEdgeNULL(G->adj[e.w][v]))
            if (G->visited[v] == 0)
                end = 0;

    if (end == 1) {
        printf("Simple path with length = %d\n", len);
        v =0;
        while (v == G->st[v])
               v++;
        while (v != G->st[v])
        {
            printf("edge %s - %s\n", TSleggiIndice(vertices, v), TSleggiIndice(vertices, G->st[v]));
            v = G->st[v];
        }
        printf("\n");
        return;
    }
}

void GRAPHallsimplepaths(Graph G, TS vertices, int start)
{
    int v;
    INITvisit(G);

    if (start != -1) {
        pathR(G, vertices, EDGE(start, start),0);
    } else {
        for (v=0; v < G->V; v++)
            if (G->visited[v] == 0)
                pathR(G, vertices, EDGE(v,v),0);
    }

    CLEANvisit(G);

}
