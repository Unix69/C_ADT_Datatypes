#ifndef QUEUE_H_DEFINED
#define QUEUE_H_DEFINED

typedef struct queue *Q;

Q       QUEUEinit(int maxN);
int     QUEUEempty(Q q);
void    QUEUEput (Q q, Item item);
Item    QUEUEget(Q q);
void    QUEUEdisplay(Q q, void (*visit) (Item));
int     QUEUEsize(Q q);

#endif
