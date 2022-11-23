#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
int main(void)
{
    int V, E, i, j, cont;
    printf("Input number of nodes: ");
    scanf("%d", &V);
    printf("Input number of edges: ");
    scanf("%d", &E);

    Graph G, GT;
    G = GRAPHinit(V);
    GT = GRAPHinit(V);

    cont = 1;
    while(cont)
    {
        printf("\nOperations on directed graphs\n");
        printf("===============\n");
        printf("1.Create random graph\n");
        printf("2.Create graph by edge insertion\n");
        printf("3.Display\n");
        printf("4.Depth-first search\n");
        printf("5.Reverse graph\n");
        printf("6.Strongly connected components\n");
        printf("7.Strongly connected nodes\n");
        printf("8.Exit\n");
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
                            while (scanf("%d%d", &i, &j)==2)
                                GRAPHinsertE(G, EDGE(i, j));
                            break;
                case 3:     GRAPHshow(G);
                            break;
                case 4:     GRAPHdfs(G);
                            break;
                case 5:     GT = GRAPHreverse(G);
                            printf("\n Reverse graph is: \n");
                            GRAPHshow(GT);
                            break;
                case 6:     printf("\n The graph has %d strongly connected component(s)\n", GRAPHscc(G));
                            break;
                case 7:     printf("Input node:");
                            scanf("%d", &i);
                            printf("Input node:");
                            scanf("%d", &j);
                            if(GRAPHstrongconnect(G, i, j))
                                printf("nodes %d and %d are strongly connected\n", i, j);
                            else
                                printf("nodes %d and %d are not strongly connected\n", i, j);
                            break;
                case 8:     cont = 0;
                            break;
                default:    printf("Invalid option\n");
            }
        }
    }
    return 0;
}
