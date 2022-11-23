#include <stdio.h>
#include <stdlib.h>
#include "POLY.h"

main(int argc, char *argv[])
{ 
  if (argc < 3) 
  {
     printf("errore: argomenti mancanti\n"); 
     printf("il formato corretto e':\n"); 
     printf("%s N p\n", argv[0]); 
     return 0;
  }
  int N = atoi(argv[1]); 
  float p = atof(argv[2]) ;
  
  Poly t, x; int i, j;
  
  printf("Binomial coefficients (x + 1)^%d\n", N) ;
 
  t = POLYadd(POLYterm(1,1), POLYterm(1,0));
 
  for (i = 0, x = t; i < N-1; i++)
    x = POLYmult(t, x); 
 
  showPOLY(x); 
 
  printf("(x + 1)^n in %f is %f\n", p, POLYeval(x, p)) ;
}
