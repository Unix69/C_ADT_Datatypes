#include <stdlib.h>
#include "Item.h"
#include "ST.h"


typedef struct STnode* link;
struct STnode { Item item; link next; } ;

struct symboltable { link head; int N; link z; };

Item NULLitem = EMPTYitem;

link NEW( Item item, link next)
{
    link x = malloc(sizeof *x);
    x->item = item; x->next = next;
    return x;
}

ST STinit( int max)
{
    ST st = malloc(sizeof *st) ;
    st->N = 0;
    st->head = ( st->z = NEW(NULLitem, NULL));
    return st;
}

int STcount(ST st)
{
    return st->N;
}

void STinsert(ST st, Item item)
{
    st->head = NEW(item, st->head);
    st->N++;
}

Item searchR(link t, Key k, link z)
{
    if (t == z)
        return NULLitem;
    if (eq(key(t->item), k))
        return t->item;
    return
        searchR(t->next, k, z);
}

Item STsearch(ST st, Key k)
{
    return searchR(st->head, k, st->z);
}

void STdisplay(ST st, void (*visit)(Item))
{
link x;
    x = st->head;
    while (x != st->z)
    {
        visit(x->item);
        x = x->next;
    }

}

link deleteR(link x, Item item)
{
     if ( x == NULL )
        return NULL;
     if (eq(key(x->item), key(item)))
     {
          link t = x->next;
          free(x);
          return t;
     }
     x->next = deleteR(x->next, item);
     return x;
}

void STdelete(ST st, Item item)
{
    st->head = deleteR(st->head, item);
    st->N--;
}
