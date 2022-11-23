typedef struct queue *Q;

Q QUEUEinit(int maxN);
int QUEUEempty(Q q);
void QUEUEput (Q q, Item item);
Item QUEUEget(Q q);
