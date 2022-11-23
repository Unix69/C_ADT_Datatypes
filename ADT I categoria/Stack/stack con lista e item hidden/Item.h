#ifndef ITEM_H_DEFINED
#define ITEM_H_DEFINED

#define MAX 10

typedef struct item *Item;

Item ITEMnew();
void ITEMscan(Item x);
void ITEMshow(Item x);

#endif
