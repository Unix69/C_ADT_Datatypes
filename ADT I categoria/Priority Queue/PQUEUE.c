#include <stdlib.h>
#include "Item.h"
#include "PQUEUE.h"
#define LEFT(i)   	((i*2) + 1)
#define RIGHT(i)	((i*2) + 2)
#define PARENT(i)	((i-1) / 2)

struct pqueue { Item *array; int heapsize; };

PQ PQUEUEinit(int maxN)
{
    PQ pq;
    pq = malloc(sizeof(*pq));
    pq->array = (Item *)malloc(maxN*sizeof(Item));
    pq->heapsize = 0;
    return pq;
}

int PQUEUEempty(PQ pq)
{
    return pq->heapsize == 0;
}

int PQUEUEsize(PQ pq)
{
    return pq->heapsize;
}

void PQUEUEinsert (PQ pq, Item item)
{
    int i;
    i  = pq->heapsize++;
	while (i>=1 && less(pq->array[PARENT(i)], item))
    {
        pq->array[i] = pq->array[PARENT(i)];
		i = (i-1)/2;
    }
	pq->array[i] = item;
	return;
}

void Swap(PQ pq, int n1, int n2)
{
	Item temp;

	temp  = pq->array[n1];
	pq->array[n1] = pq->array[n2];
	pq->array[n2] = temp;
	return;
}

void Heapify(PQ pq, int i)
{
    int l, r, largest;
    l = LEFT(i);
    r = RIGHT(i);
    if (l < pq->heapsize && greater(pq->array[l], pq->array[i]))
        largest = l;
    else
        largest = i;
    if (r < pq->heapsize && greater(pq->array[r], pq->array[largest]))
        largest = r;
    if (largest != i)
    {
		Swap(pq, i,largest);
		Heapify(pq, largest);
    }
    return;
}

Item PQUEUEextractMax(PQ pq)
{
    Item item;
    Swap (pq, 0,pq->heapsize-1);
    item = pq->array[pq->heapsize-1];
    pq->heapsize--;
    Heapify(pq, 0);
	return item;
}

Item PQUEUEshowMax(PQ pq)
{
  return pq->array[0];
}

void PQUEUEdisplay(PQ pq, void (*visit) (Item))
{
    int i;
    for (i = 0; i < pq->heapsize; i++)
    {
        visit(pq->array[i]);
    }
}
void PQUEUEchange (PQ pq, int pos, Item item)
{
	while (pos>=1 && less(pq->array[PARENT(pos)], item))
    {
        pq->array[pos] = pq->array[PARENT(pos)];
		pos = (pos-1)/2;
    }
	pq->array[pos] = item;
	Heapify(pq, pos);
	return;
}
