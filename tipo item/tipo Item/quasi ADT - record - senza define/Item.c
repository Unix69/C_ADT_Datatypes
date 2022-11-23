// implementazione di Item record (con campo stringa e numero)
// la chiave e' la stringa

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"

static char *key(Item *pA) {
  return (pA->name);
}

int less(Item A, Item B) {
  return (strcmp(key(&A),key(&B))<0);
}

void exch(Item *pA, Item *pB) {
  Item t = *pA; 
  *pA = *pB; 
  *pB = t;
}

void compexch(Item *pA, Item *pB) {
  if (less(*pB,*pA)) 
    exch(pA,pB);
}

int ITEMscan(Item *px) {
  int t;
  t = scanf("%29s %d", px->name, &(px->num));
  return t;
}
void ITEMshow(Item x) {
  printf("%s %d", x.name, x.num);
}
