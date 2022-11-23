#ifndef PQ_H_DEFINED
#define PQ_H_DEFINED

typedef struct pqueue *PQ;

PQ      PQUEUEinit(int);
int     PQUEUEempty(PQ) ;
void    PQUEUEdisplay(PQ pq);
void    PQUEUEinsert(PQ, int *,  int);
int     PQUEUEextractMin(PQ, int *);
void    PQUEUEchange(PQ, int *,  int);
#endif
