#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

static Item *s;
static int *t;
static int N;

void STACKinit(int maxN)
{ 
  int i;
  s = malloc(maxN*sizeof(Item)); 
  t= malloc(maxN*sizeof(Item)); 
  for (i=0; i<maxN; i++) t[i]=0;
  N=0; 
}

int STACKempty()
{ 
  return N == 0; 
}

void STACKpush(Item item)
{ 
  if (t[item] == 1) return;
  s[N++] = item; 
  t[item] = 1;
}

Item STACKpop()
{ 
  --N;
  t[s[N]] = 0;
  return s[N]; 
}
