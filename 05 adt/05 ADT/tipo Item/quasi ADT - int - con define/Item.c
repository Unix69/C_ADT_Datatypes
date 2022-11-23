#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

int ITEMscan(int *px) {
  return scanf("%d", px);
}
void ITEMshow(int x) {
  printf("%d", x);
}