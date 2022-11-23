#ifndef QUEUE_H_DEFINED
#define QUEUE_H_DEFINED

typedef struct queue *Q;

Q       QUEUEinit();
int     QUEUEempty(Q q);
void    QUEUEput (Q q, Edge e);
Edge    QUEUEget(Q q);
void    QUEUEdisplay(Q q, void (*visit) (Edge));
int     QUEUEsize(Q q);

#endif
