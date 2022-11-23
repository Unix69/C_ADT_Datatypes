#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "IBST.h"

typedef struct IBSTnode* link;
struct IBSTnode { Item item; link l, r; int N; int max; } ;

struct intervalbinarysearchtree { link head; int N; link z; };

Item NULLitem = EMPTYitem;

link NEW(Item item, link l, link r, int N, int max)
{
    link x = malloc(sizeof *x);
    x->item = item; x->l = l; x->r = r; x->N = N; x->max = max;
    return x;
}

IBST IBSTinit( )
{
    IBST ibst = malloc(sizeof *ibst) ;
    ibst->N = 0;
    ibst->head = ( ibst->z = NEW(NULLitem, NULL, NULL, 0, -1));
    return ibst;
}
int IBSTcount(IBST ibst)
{
    return ibst->N;
}

int IBSTempty(IBST ibst)
{
    if ( IBSTcount(ibst) == 0)
        return 1;
    else
        return 0;
}

Item searchR(link h, Item item, link z)
{
    if (h == z)
        return NULLitem;
    if (overlap(item, h->item))
        return h->item;
    if (less_int(item, h->item))
        return searchR(h->l, item, z);
    else
        return searchR(h->r, item, z);
  }

Item IBSTsearch(IBST ibst, Item item)
{
    return searchR(ibst->head, item, ibst->z);
}

int max (int a, int b, int c)
{
    int m = a;
    if (b > m)
        m = b;
    if (c > m)
        m = c;
    return m;
}

link insertR(link h, Item item, link z)
{
    if (h == z)
        return NEW(item, z, z, 1, high(item));
    if (less(key(item), key(h->item)))
    {
        h->l = insertR(h->l, item, z);
        h->max = max(h->max, h->l->max, h->r->max);
    }
    else
    {
        h->r = insertR(h->r, item, z);
        h->max = max(h->max, h->l->max, h->r->max);
    }
    (h->N)++;
    return h;
}

void IBSTinsert(IBST ibst, Item item)
{
    ibst->head = insertR(ibst->head, item, ibst->z);
    ibst->N++;
}


link rotR(link h)
{
    link x = h->l;
    h->l = x->r;
    x->r = h;
    x->N = h->N;
    h->N = h->r->N + h->l->N +1;
    h->max = max(high(h->item), h->l->max, h->r->max);
    x->max = max(high(x->item), x->l->max, x->r->max);
    return x;
}

link rotL(link h)
{
    link x = h->r;
    h->r = x->l;
    x->l = h;
    x->N = h->N;
    h->N = h->l->N + h->r->N +1;
    h->max = max(high(h->item), h->l->max, h->r->max);
    x->max = max(high(x->item), x->l->max, x->r->max);
    return x;
}

void sortinorderR(link h, void (*visit) (Item), link z)
{
    if (h == z)
        return;
    sortinorderR(h->l, visit, z);
    visit(h->item);
    printf("h->max = %d \n", h->max);
    sortinorderR(h->r, visit, z);
}

void IBSTsortinorder(IBST ibst, void (*visit)(Item))
{
    sortinorderR(ibst->head, visit, ibst->z);
}

void sortpostorderR(link h, void (*visit) (Item), link z)
{
    if (h == z)
        return;
    sortpostorderR(h->l, visit, z);
    sortpostorderR(h->r, visit, z);
    visit(h->item);
    printf("h->max = %d \n", h->max);
}

void IBSTsortpostorder(IBST ibst, void (*visit)(Item))
{
    sortpostorderR(ibst->head, visit, ibst->z);
}

void sortpreorderR(link h, void (*visit) (Item), link z)
{
    if (h == z)
        return;
    visit(h->item);
    printf("h->max = %d \n", h->max);
    sortpreorderR(h->l, visit, z);
    sortpreorderR(h->r, visit, z);
}

void IBSTsortpreorder(IBST ibst, void (*visit)(Item))
{
    sortpreorderR(ibst->head, visit, ibst->z);
}

link partR(link h, int k)
{
    int t  = h->l->N;
    if ( t > k)
    {
        h->l = partR(h->l, k);
        h = rotR(h);
    }
    if ( t < k)
    {
        h->r = partR(h->r, k-t-1);
        h = rotL(h);
    }
   	return h;
}

link joinLR(link a, link b, link z)
{
    if (b == z)
        return a;
    b = partR(b, 0);
    b->l = a;
    b->N = a->N + b->r->N +1;
    b->max = max(high(b->item), a->max, b->r->max);

    return b;
}

link deleteR(link h, Item item, link z)
{
    link x;
    if (h == z)
        return z;
    if (less(key(item), key(h->item)))
    {
        h->l = deleteR(h->l, item, z);
        h->max = max(high(h->item), h->l->max, h->r->max);
    }
    if (less(key(h->item), key(item)))
    {
        h->r = deleteR(h->r, item, z);
        h->max = max(high(h->item), h->l->max, h->r->max);
    }
    (h->N)--;
    if (eq(item, h->item))
    {
        x = h;
        h = joinLR(h->l, h->r, z);
        free(x);
    }
    return h;
}

void IBSTdelete(IBST ibst, Item item)
{
    ibst->head = deleteR(ibst->head, item, ibst->z);
    ibst->N--;
}

