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
    int j = st->size++;
    while (j > 0 && less(key(item), key(st->a[j-1])))
    {
        st->a[j] = st->a[j-1];
        j--;
    }
    st->a[j] = item;
}

Item searchR(ST st, int l, int r, Key k)
{
    int m = (l + r)/2;
    if (l > r)
        return NULLitem;
    if eq(k, key(st->a[m]))
        return st->a[m];
    if (l == r)
        return NULLitem;
    if less(k, key(st->a[m]))
        return searchR(st, l, m-1, k);
    else
        return searchR(st, m+1, r, k);
  }


Item STsearch(ST st, Key k)
{
    return searchR(st, 0, st->size-1, k) ;
}

void STdelete(ST st, Item v)
{
    int i, j;
    j = 0;
    while (less(key(st->a[j]), key(v)))
        j++;
    for (i = j; i < st->size-1; i++)
        st->a[i] = st->a[i+1];
    st->size--;
}

Item STselect(ST st, int r)
{
    return st->a[r];
}


void STdisplay(ST st, void (*visit) (Item))
{
    int i;
    for (i = 0; i < st->size; i++)
        if (neq(key(st->a[i]), key(NULLitem)))
            visit(st->a[i]);
}
