// quasi ADT: no handle (Item.h lascia vedere il typedef al client)
// nessuna funzionalita' realizzata con #define (ma tutte con funzioni)
// la chiave (key) e' di tipo int
// ATTENZIONE exch e compexch sono diverse dalle versioni #define, in quanto 
// ricevono puntatori agli Item da scambiare

typedef char *Item;

int less(Item A, Item B);
void exch(Item *pA, Item *pB);
void compexch(Item *pA, Item *pB);

int ITEMscan(Item *x);
void ITEMshow(Item x);