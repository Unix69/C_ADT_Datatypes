#include <stdio.h>
#include "equivalenceADT.h"

main(int argc, char *argv[])
{ 
  int p, q ;
  if (argc < 2) 
  {
     printf("errore: argomento mancante\n"); 
     printf("il formato corretto e':\n"); 
     printf("%s N \n", argv[0]); 
     return 0;
  }

  int N = atoi(argv[1]) ;
  
  UFinit(N) ;
  printf("Input pair p q:  ");
  while (scanf("%d %d", &p, &q) == 2)
  {
        if (UFfind(p,q))
		  printf("pair %d %d already connected\n", p,q);
        else
        {
          UFunion(p,q);
          printf("pair %d %d not yet connected\n", p, q);
        }
        printf("Input pair p q:  ");
  }
  system("pause");










}
