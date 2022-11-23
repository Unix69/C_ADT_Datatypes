// ADT I cat con handle (Item.h nasconde i dettagli della struct al client)
// nessuna funzionalita' realizzata con #define (ma tutte con funzioni)

#define NULLitem NULL

typedef struct record *Item;

int less(Item A, Item B);
void exch(Item *pA, Item *pB);
void compexch(Item *pA, Item *pB);

int ITEMscan(Item *x);
void ITEMshow(Item x);
void ITEMfree(Item x);