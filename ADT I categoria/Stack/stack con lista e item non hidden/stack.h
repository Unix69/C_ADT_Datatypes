#ifndef STACK_H_DEFINED
#define STACK_H_DEFINED

typedef struct stack *S;

S    STACKinit(int maxN);
int  STACKempty(S);
int  STACKsize(S);
void STACKpush(S, Item);
Item STACKpop(S);
Item STACKtop(S);
void STACKdisplay(S, void (*visit) (Item));

#endif
