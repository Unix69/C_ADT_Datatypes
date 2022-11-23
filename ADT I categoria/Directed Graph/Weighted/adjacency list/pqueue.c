#include <stdlib.h>
#include <stdio.h>
#include "PQUEUE.h"
#define LEFT(i)   	((i*2) + 1)
#define RIGHT(i)	((i*2) + 2)
#define PARENT(i)	((i-1) / 2)

struct pqueue { int *array; int heapsize; };

PQ PQUEUEinit(int maxN)
{
    PQ pq;
    pq = malloc(sizeof(*pq));
    pq->array = (int *)malloc(maxN*sizeof(int));
    pq->heapsize = 0;
    return pq;
}

int PQUEUEempty(PQ pq)
{
    return pq->heapsize == 0;
}

void PQUEUEdisplay(PQ pq)
{
    int i;
    for (i = 0; i < pq->heapsize; i++)
        printf("%d \n", pq->array[i]);
}

void PQUEUEinsert (PQ pq, int mindist[], int node)
{
    int i;
    i  = pq->heapsize++;
	while (i>=1 && (mindist[pq->array[PARENT(i)]] > mindist[node]))
    {
        pq->array[i] = pq->array[PARENT(i)];
		i = (i-1)/2;
    }
	pq->array[i] = node;
	return;
}

void Swap(PQ pq, int n1, int n2)
{
	int temp;

	temp  = pq->array[n1];
	pq->array[n1] = pq->array[n2];
	pq->array[n2] = temp;
	return;
}

void Heapify(PQ pq, int mindist[], int i)
{
    int l, r, smallest;
    l = LEFT(i);
    r = RIGHT(i);
    if (l < pq->heapsize && (mindist[pq->array[l]] < mindist[pq->array[i]]))
        smallest = l;
    else
        smallest = i;
    if (r < pq->heapsize && (mindist[pq->array[r]] < mindist[pq->array[smallest]]))
        smallest = r;
    if (smallest != i)
    {
		Swap(pq, i,smallest);
		Heapify(pq, mindist, smallest);
    }
    return;
}

int PQUEUEextractMin(PQ pq, int mindist[])
{
    int priority;
    Swap (pq, 0,pq->heapsize-1);
    priority = pq->array[pq->heapsize-1];
    pq->heapsize--;
    Heapify(pq, mindist, 0);
	return priority;
}

void PQUEUEchange (PQ pq, int mindist[], int node)
{
    int pos;
    pos = 0;
    while (pq->array[pos] != node)
        pos++;
	while (pos>=1 && (mindist[pq->array[PARENT(pos)]] > mindist[pq->array[pos]]))
    {
        pq->array[pos] = pq->array[PARENT(pos)];
		pos = (pos-1)/2;
    }
	pq->array[pos] = node;
	Heapify(pq, mindist, pos);
	return;
}

