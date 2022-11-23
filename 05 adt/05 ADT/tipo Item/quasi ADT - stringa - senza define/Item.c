#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"

#define MAXC 1000
static char buf[MAXC];

static char *key(Item A) {
  return (A);
}

int less(Item A, Item B) {
  return (strcmp(key(A),key(B))<0);
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

int ITEMscan(char **px) {
  int t;
  t = scanf("%999s",buf);
  *px = strdup(buf);
  return t;
}
void ITEMshow(char *x) {
  printf("%s", x);
}
