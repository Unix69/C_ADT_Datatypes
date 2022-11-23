#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "COMPLEX.h"

#define PI 3.141592625

main(int argc, char *argv[])
{ 
  int i, j ;
  Complex t, x;
  
  if (argc < 2) 
  {
     printf("errore: argomento mancante\n"); 
     printf("il formato corretto e':\n"); 
     printf("%s N\n", argv[0]); 
     return 0;
  }

  int N = atoi(argv[1]) ;
  
  printf("radice complessa dell'unita' di ordine %d\n", N) ;
  
  for (i = 0; i < N; i++)
  { 
    float r = 2.0*PI*i/N;
    t = COMPLEXinit(cos(r), sin(r));
    printf("i = %2d Re = %6.3f Im = %6.3f \n", i, Re(t), Im(t));
    
    printf("verifico che sia davvero una radice dell'unita' \n");
    for (x = t, j = 0; j < N-1; j++)
      x = COMPLEXmult(t, x) ;
    
    printf("Re = %6.3f Im = %6.3f\n", Re(x), Im(x)) ; 
  }
}
