// quasi ADT: no handle (Item.h lascia vedere il typedef al client)
// alcune funzionalita' realizzate con #define

typedef int Item;

#define key(A) (A)
#define less(A,B) (key(A)<key(B))
#define exch(A,B) {Item t=A; A=B; B=t;}
#define compexch(A,B) if (less(A,B) exch(A,B)

int ITEMscan(int *x);
void ITEMshow(int x);