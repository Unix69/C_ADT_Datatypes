#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "Stack.h"

main(int argc, char *argv[])
{ 
  STACK st;
  
  if (argc < 2) 
  {
     printf("errore: argomento mancante\n"); 
     printf("il formato corretto e':\n"); 
     printf("%s \"espressione infissa con (, ), + e *\"\n", argv[0]); 
     return 0;
  }

  char *a = argv[1]; int i, N = strlen(a);
  
  st = STACKinit(N) ;

  for (i = 0; i < N; i++)
  {
    if (a[i] == ')')
      printf("%c ", STACKpop(st));

    if ((a[i] == '+')||(a[i] == '*'))
      STACKpush(st,a[i]);

    if ((a[i] >= '0') && (a[i] <= '9'))
      printf ("%c ", a[i]);
  }
  printf("\n") ;
}
