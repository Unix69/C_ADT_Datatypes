// versione del client che prevede allocazione e liberazione esplicita di Item

#include "Item.h"
#include <stdio.h>

int main (void) {
  Item a, b;

  a = ITEMnew();
  b = itemNew();
  
  if (a==NULLitem || b==NULLitem) {
    printf("errore in allocazione\n");
    return 0;
  }

  printf("First  Item: ");
  ITEMscan(&a);
  printf("Second Item: ");
  ITEMscan(&b);

  compexch(&a,&b);
  printf("Sorted Items:\n");
  ITEMshow(a);
  printf("\n");
  ITEMshow(b);
  printf("\n");
  
  ITEMfree(a);
  ITEMfree(b);

  return 0;
}
