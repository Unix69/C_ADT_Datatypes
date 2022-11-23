#ifndef PQ_H_DEFINED
#define PQ_H_DEFINED

typedef struct pqueue *PQ;

PQ      PQUEUEinit(int);
int     PQUEUEempty(PQ);
void    PQUEUEinsert(PQ, Item);
Item    PQUEUEextractMax(PQ);
Item    PQUEUEshowMax(PQ);
void    PQUEUEdisplay(PQ, void (*visit) (Item));
int     PQUEUEsize(PQ);
void    PQUEUEchange (PQ pq, int pos, Item item);


#endif
