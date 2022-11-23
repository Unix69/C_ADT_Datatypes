/*****************************************************************************

				MATR.C

******************************************************************************/

#include <stdio.h>
#include "matr.h"

static int mat[2][MAXR][MAXC];

int MATRinsert (int x, int y, int flag)
{
  mat[flag][x][y]=1;
  return (1);
}

void MATRreset (int flag)
{
  int	i,j;

  for (i=0; i<MAXR; i++) {
    for (j=0; j<MAXC; i++) {
      mat[flag][i][j] = 0;
    }  
  }
}

int MATRalive (int x, int y, int flag)
{
  return (mat[flag][x][y]);
}




