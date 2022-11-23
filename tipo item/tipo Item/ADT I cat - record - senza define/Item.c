// implementazione di Item record (con campo stringa e numero)
// la chiave e' la stringa
// la strinfa viene direttamente sovradimensionata nella struct record
// in questa versione, un Item viene allocato esplicitamente mediante ITEMnew
// e liberato con ITEMfree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"

#define MAXC 30

struct record {
  char name[MAXC];
  int num;
};

static char *key(Item A) {
  return (A->name);
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
  if (less(*pA,*pB)) 
    exch(pA,pB);
}

// si mantiene *px per compatibilità con altre versioni
// si assume però in questo caso di ricevere un puntatore a Item già creato
int ITEMscan(Item *px) {
  int t;
  Item p;
  p = *px;
  t = scanf("%999s %d", p->name, &(p->num));
  return t;
}
int ITEMscan(Item *px) {
  int t;
  Item p;
  p = malloc(sizeof(struct record));
  if (p==NULL) return 0;
  t = scanf("%29s %d", p->name, &(p->num));
  *px = p;
  return t;
}

void ITEMshow(Item x) {
  printf("%s %d", x->name, x->num);
}

Item ITEMnew(void) {
  Item p;
  p = malloc(sizeof(struct record));
  if (p==NULL) return NULLitem;
  p->name[0] = '\0';
  p->num = 0;
  return p;
}

void ITEMfree(Item x) {
  free (x);
}