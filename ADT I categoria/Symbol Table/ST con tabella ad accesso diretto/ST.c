#include <stdlib.h>
#include "Item.h"
#include "ST.h"

struct symboltable { Item *a; int maxN; int size;};

Item NULLitem = EMPTYitem;

ST STinit(int maxN)
{
    ST st;
    int i;
    st = malloc(sizeof(*st));
    st->a = malloc(maxN * sizeof(Item) );
    for (i = 0; i < maxN; i++)
        st->a[i] = NULLitem;
    st->maxN = maxN;
    st->size = 0;
    return st;
}

int STcount(ST st)
{
    return st->size;
}

void STinsert(ST st, Item item)
{
    st->a[key(item)] = item;
    st->size++;
}

Item STsearch(ST st, Key k)
{
    return st->a[k];
}

void STdelete(ST st, Item item)
{
    st->a[key(item)] = NULLitem;
    st->size--;
}

Item STselect(ST st, int r)
{
    int i;
    for (i = 0; i < st->maxN; i++)
        if (neq(key(st->a[i]), key(NULLitem)) && (r-- == 0))
            return st->a[i];
    return NULLitem;
}

void STdisplay(ST st, void (*visit) (Item))
{
    int i;
    for (i = 0; i < st->maxN; i++)
        if (neq(key(st->a[i]), key(NULLitem)))
            visit(st->a[i]);
}

