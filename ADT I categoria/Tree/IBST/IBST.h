#ifndef IBST_H_DEFINED
#define IBST_H_DEFINED

typedef struct  intervalbinarysearchtree *IBST;

IBST	IBSTinit() ;
int		IBSTcount(IBST) ;
int     IBSTempty(IBST) ;
void 	IBSTinsert(IBST,Item) ;
Item	IBSTsearch(IBST,Item) ;
void	IBSTdelete(IBST,Item) ;
void	IBSTsortinorder(IBST, void (*visit) (Item)) ;
void	IBSTsortpreorder(IBST, void (*visit) (Item)) ;
void	IBSTsortpostorder(IBST, void (*visit) (Item)) ;

#endif
