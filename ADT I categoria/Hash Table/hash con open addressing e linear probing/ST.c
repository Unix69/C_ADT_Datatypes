#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"
#include "ST.h"
#define full(A) (neq(key(st->a[A]), key(NULLitem)))
#define null(A) (eq(key(st->a[A]), key(NULLitem)))

struct symboltable { Item *a; int N; int M;};

Item NULLitem = EMPTYitem;

ST STinit(int maxN)
{
    ST st;
    int i;
    st = malloc(sizeof(*st));
    st->N = 0;
    st->M = maxN;
    st->a = malloc(st->M * sizeof(Item) );
    for (i = 0; i < st->M; i++)
        st->a[i] = NULLitem;
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
int hashU( char *v, int M)
{
    int h, a = 31415, b = 27183;
    for ( h = 0; *v != '\0'; v++, a = a*b % (M-1))
        h = (a*h + *v) % M;
    return h;
}
*/

int STcount(ST st)
{
    return st->N;
}

int STempty(ST st)
{
    if ( STcount(st) == 0)
        return 1;
    else
        return 0;
}

void STinsert(ST st, Item item)
{
    int i = hash(key(item), st->M);
    while (full(i))
        i = (i+1)%st->M;
    st->a[i] = item;
    st->N++;
}

Item STsearch(ST st, Key v)
{
    int i = hash(v, st->M);
    while (full(i))
      if (eq(v, key(st->a[i])))
        return st->a[i];
      else
        i = (i+1)%st->M;
    return NULLitem;
}

void STlist(ST st, void (*visit) (Item))
{
    int i;
    for (i = 0; i < st->M; i++)
    {
        printf("st->a[%d] = ", i);
        visit(st->a[i]);
        printf("\n");
    }
}

void STdelete(ST st, Item item)
{
    int j, i = hash(key(item), st->M);
    Item v;
    while (full(i))
        if eq(key(item), key(st->a[i]))
            break;
        else
            i = (i+1) % st->M;
    if (null(i))
        return;
    st->a[i] = NULLitem;
    st->N--;
    for (j = i+1; full(j); j = (j+1)%st->M, st->N--)
    {
        v = st->a[j];
        st->a[j] = NULLitem;
        STinsert(st, v);
    }
}

