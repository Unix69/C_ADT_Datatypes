#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "UF.h"

int main(void)
{
    int V, E, i, j, wt, cont;
    printf("Input number of nodes: ");
    scanf("%d", &V);
    printf("Input number of edges: ");
    scanf("%d", &E);

    Graph G;
    G = GRAPHinit(V);

    cont = 1;
    while(cont)
    {
        printf("\nOperations on weighted undirected graphs\n");
        printf("===============\n");
        printf("1.Create graph by edge insertion\n");
        printf("2.Display\n");
        printf("3. MST with Kruskal's algorithm\n");
        printf("4. MST with Prim's algorithm\n");
        printf("5.Exit\n");
        printf("Enter your choice : ");
        if(scanf("%d",&i)<=0)
        {
            printf("Integers only!\n");
            exit(0);
        }
        else
        {
            switch(i)
            {
                case 1:     printf("Insert max %d edges:\n", E);
                            printf("now insert the edges and their weights:\n");
                            while (scanf("%d%d %d", &i, &j, &wt)==3)
                                GRAPHinsertE(G, EDGE(i, j, wt));
                            break;
                case 2:     GRAPHshow(G);
                            break;
                case 3:     GRAPHmstK(G);
                            break;
                case 4:     GRAPHmstP(G);
                            break;
                case 5:     cont = 0;
                            break;
                default:    printf("Invalid option\n");
            }
        }
    }
    return 0;
}
