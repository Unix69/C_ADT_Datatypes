#include <stdlib.h>
#include "Item.h"
#include "stack.h"

typedef struct STACKnode* link;
struct STACKnode
{
    Item item;
    link next;
};

struct stack {link top; int N; };


link NEW(Item item, link next)
{
    link x = malloc(sizeof *x);
    x->item = item;
    x->next = next;
    return x;
}

S STACKinit(int MaxN)
{
    S s = malloc(sizeof *s);
    s->top = NULL;
    s->N = 0;
    return s;
}

int STACKempty(S s)
{
    return s->top == NULL;
}

int STACKsize(S s)
{
    return s->N;
}

void STACKpush(S s, Item item)
{
    if (s->top == NULL)
    {
        s->top = NEW(item, s->top);
       (s->N)++;
        return;
    }
    s->top = NEW(item, s->top);
    (s->N)++;
}

Item STACKpop(S s)
{
    Item item = s->top->item;
    link t = s->top->next;
    free(s->top);
    s->top = t;
    (s->N)--;
    return item;
}

Item STACKtop(S s)
{
    return s->top->item;
}

void STACKdisplay(S s, void (*visit) (Item))
{
    link x;
    x = s->top;
    while (x != NULL)
    {
        visit(x->item);
        x = x->next;
    }
}
