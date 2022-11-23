#include <stdlib.h>
#include "Item.h"
#include "Stack.h"

typedef struct STACKnode* link;

struct STACKnode { Item item; link next; };

static link head;

static link NEW (Item item, link next)
{ link x = (STACKnode *) malloc(sizeof *x);
  x->item = item; x->next = next;
  return x;
}

void STACKinit(int maxN)
{ head = NULL; }

int STACKempty()
{ return head == NULL; }

void STACKpush(Item item)
{ head = NEW(item, head); }
 
Item STACKpop ()
{ Item item;
  if (head==NULL) return 0; 
  item = head->item;
  link t = head->next;
  free (head); head = t;
  return item;
}

