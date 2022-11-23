// quasi ADT: no handle (Item.h lascia vedere il typedef al client)
// nessuna funzionalita' realizzata con #define (ma tutte con funzioni)

#define MAXC 30

typedef struct record {
  char name[MAXC];
  int num;
} Item;

int less(Item A, Item B);
void exch(Item *pA, Item *pB);
void compexch(Item *pA, Item *pB);

int ITEMscan(Item *x);
void ITEMshow(Item x);