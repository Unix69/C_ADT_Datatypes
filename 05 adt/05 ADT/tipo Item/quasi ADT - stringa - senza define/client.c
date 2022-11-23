#include "Item.h"
#include <stdio.h>

int main (void) {
  Item a, b;

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

  return 0;
}
