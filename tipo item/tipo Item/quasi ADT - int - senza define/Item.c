#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

static int key(Item A) {
  return (A);
}

int less(Item A, Item B) {
  return (key(A)<key(B));
}

void exch(Item *pA, Item *pB) {
  Item t = *pA; 
  *pA = *pB; 
  *pB = t;
}

void compexch(Item *pA, Item *pB) {
  if (less(*pA,*pB)) 
    exch(pA,pB);
}

int ITEMscan(Item *px) {
  return scanf("%d", px);
}
void ITEMshow(Item x) {
  printf("%d", x);
}