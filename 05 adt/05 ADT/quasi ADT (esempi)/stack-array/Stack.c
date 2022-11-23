#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

static Item *s;
static int N, M;

void STACKinit(int maxN)
{ s = malloc(maxN*sizeof(Item)); N=0; M=maxN; }

int STACKempty()
{ return N == 0; }
int STACKfull()
{ return N == M; }

void STACKpush(Item item)
{ s[N++] = item; }

Item STACKpop()
{ return s[--N]; }
