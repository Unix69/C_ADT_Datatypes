#ifndef ITEM_H_DEFINED
#define ITEM_H_DEFINED

#define EMPTYitem { -1, " " }
#define eq(A, B) ((strcmp(A, B) == 0))
#define neq(A, B) ((strcmp(A, B) != 0))
#define less(A, B) ((strcmp(A, B) == -1))
#define key(A) (A.str)
#define MAX 10

typedef struct { int x; char str[MAX]; } Item;
typedef char* Key;

Item ITEMscan();
void ITEMshow(Item x);

#endif
