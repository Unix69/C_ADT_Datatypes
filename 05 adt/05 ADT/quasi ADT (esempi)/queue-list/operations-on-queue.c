#include <stdio.h>
#include "Item.h"
#include "QUEUE.h"

main(int argc, char *argv[])
{ 
  if (argc < 2) 
  {
     printf("errore: argomento mancante\n"); 
     printf("il formato corretto e':\n"); 
     printf("%s \"stringa di lettere con * per get\" \n", argv[0]); 
     return 0;
  }
  char *a = argv[1]; 
  int i, N = strlen(a) ;
  QUEUEinit(N) ;
  
  for (i = 0; i < N; i++)
  {
    if ((a[i] >= 'A') && (a[i] <= 'Z'))
      QUEUEput(a[i]) ;
    if (a[i] == '*')
      printf("dequeued element %c \n", QUEUEget());
  }
  system("pause");
}


