#include <stdio.h>
#include <stdlib.h>
#include "Dag.h"

int main (int argc, char *argv[])
{
    Dag D;
    int V = atoi(argv[1]);
    int i, j;

    if (argc !=2)
    {
        printf("Error in command line, correct format: \n");
        printf("main <V> \n");
        exit(1);
    }

    printf("create DAG by edge insertion, then reverse topological sort \n");

    D = DAGinit(V);
    printf("insert edges:\n");
    while (scanf("%d%d", &i, &j)==2)
        DAGinsertE(D, EDGE(i, j));

    printf("the DAG's adjacency list has \n");
    DAGshow(D);

    printf("reverse topological sort \n");

    DAGrts(D);

    return 1;
}
