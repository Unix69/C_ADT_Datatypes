#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"
#include "ST.h"
#define full(A) (neq(key(st->a[A]), key(NULLitem)))
#define null(A) (eq(key(st->a[A]), key(NULLitem)))
#define c1 1
#define c2 1

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
    int index = hash(key(item), st->M);
    int i = 0;

    while (full(index))
    {
        i++;
        index = (index + c1*i + c2*i*i)%st->M;
    }
    st->a[index] = item;
    st->N++;
}

Item STsearch(ST st, Key v)
{
    int index = hash(v, st->M);
    int i = 0;
    while (full(index))
        if (eq(v, key(st->a[index])))
            return st->a[index];
        else
        {
            i++;
            index = (hash(v, st->M) + c1*i + c2*i*i)%st->M;
        }
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
    int i = 0, j, index = hash(key(item), st->M);
    Item v;
    while (full(index))
        if eq(key(item), key(st->a[index]))
            break;
        else
            index = (hash(key(item), st->M) + c1*i + c2*i*i) % st->M;
    if (null(index))
        return;
    st->a[index] = NULLitem;
    st->N--;
    for (j = index+1; full(j); j = (j+1)%st->M, st->N--)
    {
        v = st->a[j];
        st->a[j] = NULLitem;
        STinsert(st, v);
    }
}

