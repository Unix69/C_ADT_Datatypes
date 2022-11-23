#ifndef ST_H_DEFINED
#define ST_H_DEFINED

typedef struct symboltable *ST;

ST  	STinit(int) ;
int		STcount(ST) ;
void 	STinsert(ST,Item) ;
Item	STsearch(ST,Key) ;
void	STdelete(ST,Item) ;
Item    STselect(ST,int)  ;
void	STdisplay(ST, void (*visit) (Item)) ;

#endif
