#include <stdio.h>
#include "Item.h"
#include "STACK.h"

main(int argc, char *argv[])
{ 
  if (argc < 2) 
  {
     printf("errore: argomento mancante\n"); 
     printf("il formato corretto e':\n"); 
     printf("%s \"stringa di lettere con * per pop\" \n", argv[0]); 
     return 0;
  }
  char *a = argv[1]; 
  int i, N = strlen(a) ;
  STACKinit(N) ;
  
  for (i = 0; i < N; i++)
  {
    if ((a[i] >= 'A') && (a[i] <= 'Z'))
      STACKpush(a[i]) ;
    if (a[i] == '*')
      printf("popped element %c \n", STACKpop());
  }
  system("pause");
}


