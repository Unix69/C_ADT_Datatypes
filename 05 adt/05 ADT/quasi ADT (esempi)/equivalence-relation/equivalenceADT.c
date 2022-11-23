#include <stdlib.h>
#include "equivalenceADT.h"

static int *id;

void UFinit(int N)
{ int i;
  id = malloc(N*sizeof(int));
  for (i = 0; i < N; i++) 
      id[i] = i; 
}

static int find(int x)
{ int i = x;
  while (i != id[i])  
      i = id[i]; 
  return i; 
}

int UFfind(int p, int q)
{ return (find(p) == find(q)); }

void UFunion(int p, int q)
{ int i = find(p), j = find(q);
  if (i == j) return;
  id[i] = j; 
}

