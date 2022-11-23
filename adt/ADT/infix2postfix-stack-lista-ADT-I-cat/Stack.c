#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

typedef struct STACKnode* link;
struct STACKnode { Item item; link next; };

struct stack { link head; };

static link NEW (Item item, link next)
{ 
  link x = (STACKnode *) malloc(sizeof *x);
  x->item = item; x->next = next;
  return x;
}

STACK STACKinit(int maxN)
{ 
  STACK s = malloc(sizeof *s) ;
  s->head = NULL;
  return s;
}

int STACKempty(STACK s)
{ return s->head == NULL; }

void STACKpush(STACK s, Item item)
{ s->head = NEW(item, s->head); }
 
Item STACKpop (STACK s)
{ Item item;
  if (s->head==NULL) return 0; 
  item = s->head->item;
  link t = s->head->next;
  free (s->head); s->head = t;
  return item;
}

