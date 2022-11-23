#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "QUEUE.h"

#define M 10

main (int argc, char *argv[])
{
  int i, j;
  Q queues[M];

  if (argc < 2) 
  {
     printf("errore: argomento mancante\n"); 
     printf("il formato corretto e':\n"); 
     printf("%s N\n", argv[0]); 
     return 0;
  }

  int N = atoi(argv[1]);

  for (i=0; i < M; i++)
    queues[i] = QUEUEinit(N);

  for (i=0; i<N; i++)
    QUEUEput(queues[rand()%M],rand());

  for (i=0; i<M; i++, printf ( "\n" ))
  {
    printf("estrazione dalla coda %d\n", i);
    for (j=0; !QUEUEempty(queues[i]); j++)
      printf("%3d ", QUEUEget(queues[i]));
  }
}

