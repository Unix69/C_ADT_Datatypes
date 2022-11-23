#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"
#include "ST.h"

typedef struct STnode* link;
struct STnode { Item item; link next; } ;

struct symboltable { link *heads; int M; link z; };

Item NULLitem = EMPTYitem;

link NEW( Item item, link next)
{
    link x = malloc(sizeof *x);
    x->item = item; x->next = next;
    return x;
}

ST STinit(int maxN)
{
    int i;
    ST st = malloc(sizeof *st) ;
    st->M = maxN/5;
    st->heads = malloc(st->M*sizeof(link));
    st->z = NEW(NULLitem, NULL);
    for (i=0; i < st->M; i++)
        st->heads[i] = st->z;
    return st;
}

int hash(Key v, int M)
{
    int h = 0, base = 127;
    for ( ; *v != '\0'; v++)
        h = (base * h + *v) % M;
    return h;
}
/*

int hashU(Key *v, int M)
{
    int h, a = 31415, b = 27183;
    for ( h = 0; *v != '\0'; v++, a = a*b % (M-1))
        h = (a*h + *v) % M;
    return h;
}
*/

void STinsert (ST st, Item item)
{
    int i = hash(key(item), st->M);
    st->heads[i] = NEW(item, st->heads[i]); }


Item searchR(link t, Key v, link z)
{
    if (t == z)
        return NULLitem;
    if (eq(key(t->item), v))
        return t->item;
    return
        searchR(t->next, v, z);
}

Item STsearch(ST st, Key v)
{
      return searchR(st->heads[hash(v, st->M)], v, st->z);
}

link deleteR(link x, Item v)
{
     if ( x == NULL ) return NULL;
     if (eq(key(x->item), key(v)))
     {
          link t = x->next;
          free(x);
          return t;
     }
     x->next = deleteR(x->next, v);
     return x;
}

void STdelete(ST st, Item item)
{
    int i = hash(key(item), st->M);
    st->heads[i] = deleteR(st->heads[i], item);
}

void visitR(link h, void (*visit) (Item), link z)
  {
    if (h == z) return;
    visit(h->item);
    visitR(h->next, visit, z);
  }

void STlist(ST st, void (*visit)(Item))
  {
    int i;
    for (i=0; i < st->M; i++)
    {
        printf("st->heads[%d] = ", i);
        visitR(st->heads[i], visit, st->z);
        printf("\n");
    }
  }


