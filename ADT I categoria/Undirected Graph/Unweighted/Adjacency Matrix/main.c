#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int main(void)
{
    int V, E, i, j, v, w, cont;
    printf("Input number of nodes: ");
    scanf("%d", &V);
    printf("Input number of edges: ");
    scanf("%d", &E);

    Graph G;
    G = GRAPHinit(V);

    cont = 1;
    while(cont)
    {
        printf("\nOperations on undirected graphs\n");
        printf("===============\n");
        printf("1.Create random graph\n");
        printf("2.Create graph by edge insertion\n");
        printf("3.Display\n");
        printf("4.Search for simple path\n");
        printf("5.Search for Hamiltonian path\n");
        printf("6.Breadth-first search\n");
        printf("7.Exit\n");
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
                case 1:     G = GRAPHrand(G, V, E);
                            break;
                case 2:     printf("Insert max %d edges:\n", E);
                            while (scanf("%d %d", &i, &j)==2)
                                GRAPHinsertE(G, EDGE(i, j));
                            break;
                case 3:     GRAPHshow(G);
                            break;
                case 4:     printf("Insert node: ");
                            scanf("%d", &v);
                            printf("Insert node: ");
                            scanf("%d", &w);
                            GRAPHpath(G, v, w);
                            break;
                case 5:     printf("Insert start node: ");
                            scanf("%d", &v);
                            printf("Insert node: ");
                            scanf("%d", &w);
                            GRAPHpathH(G, v, w);
                            break;
                case 6:     GRAPHbfs(G);
                            break;
                case 7:     cont = 0;
                            break;
                default:    printf("Invalid option\n");
            }
        }
    }
    return 0;
}
