// Implementazione di Item record (con campo stringa e numero)
// la chiave e' la stringa
// Questa versione prevede il campo nome come striga dinamica
// che viene allocata al momento della lettura.
// si usa una stringa statica (vettore buf) per fare la lettura vera e propria
// da questa si passa all'allocazione mediante strdup
// si ricorda che strdup equivale a malloc e strcpy

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"

#define MAXC 1000
static char buf[MAXC];

struct record {
  char *name;
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
  if (less(*pB,*pA)) 
    exch(pA,pB);
}

// si mantiene *px per compatibilità con altre versioni
// si assume però in questo caso di ricevere un puntatore a Item già creato
int ITEMscan(Item *px) {
  int t;
  Item p;
  p = *px;
  t = scanf("%999s %d", buf, &(p->num));
  p->name = strdup(buf);
  return t;
}

void ITEMshow(Item x) {
  printf("%s %d", x->name, x->num);
}

Item ITEMnew(void) {
  Item p;
  p = malloc(sizeof(struct record));
  if (p==NULL) return NULLitem;
  p->name = NULL;
  p->num = 0;
  return p;
}

void ITEMfree(Item x) {
  free (x->name);
  free (x);
}
