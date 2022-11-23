#ifndef ITEM_H_DEFINED
#define ITEM_H_DEFINED

#define neq(A, B) (A != B)
#define eq(A, B) (A == B)
#define less(A, B) (A < B)
#define EMPTYitem { -1, -1 }
#define key(A) (A.x)
#define maxKey 100

typedef struct { int x; int y; } Item;
typedef int Key;

Item ITEMscan();
void ITEMshow(Item x);
Item ITEMrand();

Item ITEMscan();
void ITEMshow(Item x);
Item ITEMrand();

#endif
