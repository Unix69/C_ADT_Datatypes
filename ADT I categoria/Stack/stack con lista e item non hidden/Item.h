#ifndef ITEM_H_DEFINED
#define ITEM_H_DEFINED

#define MAX 10

typedef struct { int x; char str[MAX]; } Item;

Item ITEMscan();
void ITEMshow(Item x);

#endif
