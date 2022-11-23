#ifndef ITEM_H_DEFINED
#define ITEM_H_DEFINED

#define less(A, B) (key(A) < key(B))
#define greater(A, B) (key(A) > key(B))
#define MAX 10

typedef struct { int x; char str[MAX]; } Item;
typedef int Key;

Key key(Item x);
Item ITEMscan();
void ITEMshow(Item x);
Item ITEMrand();

#endif
