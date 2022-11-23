#include <stdlib.h>
#include "Item.h"
#include "QUEUE.h"

typedef struct QUEUEnode *link;

struct QUEUEnode{ Item item; link next; };

struct queue { link head; link tail; int size; };

link NEW(Item item, link next)
{
  link x = malloc(sizeof *x) ;
  x->item = item; x->next = next;
  return x;
}

Q QUEUEinit(int maxN)
{
  Q q = malloc(sizeof *q) ;
  q->head = NULL;
  return q;
}

int QUEUEempty(Q q)
{
  return q->head == NULL;
}

int QUEUEsize(Q q)
{
    link x;
    int n = 0;
    x = q->head;
    while (x != NULL)
    {
        n++;
        x = x->next;
    }
    return n;
}

void QUEUEput (Q q, Item item)
{
  if (q->head == NULL)
  {
        q->tail = NEW(item, q->head) ;
        q->head = q->tail;
        return;
  }
  q->tail->next = NEW(item, q->tail->next) ;
  q->tail = q->tail->next;
}

Item QUEUEget(Q q)
{
  Item item = q->head->item;
  link t = q->head->next;
  free(q->head);
  q->head = t;
  q->size--;
  return item;
}

void QUEUEdisplay(Q q, void (*visit) (Item))
{
    link x;
    x = q->head;
    while (x != NULL)
    {
        visit(x->item);
        x = x->next;
    }
}
