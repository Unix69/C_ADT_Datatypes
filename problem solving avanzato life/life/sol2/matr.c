/*****************************************************************************

				MATR.C

******************************************************************************/

#include <stdio.h>

#include "matr.h"

typedef struct cell {
  int	       y;
  struct cell *next;
} cell_t;

cell_t *mat[2][MAXR];
int	i;


int MATRinsert (int x, int y, int flag)
{
cell_t *p, *q;

if ((p = (cell_t *) malloc (sizeof (cell_t))) == NULL) {
  printf( "Errore in allocazione memoria\n");
  return( 0);
}

p->y = y;
p->next = NULL;

q = mat[flag][x];

if( q == NULL)
  mat[flag][x] = p;
else {
  while (q->next != NULL)
    q = q->next;
  q->next = p;
}

return (1);

}

void MATRreset( int flag)
{
cell_t *p, *q;
int	i;

for (i=0; i<MAXR; i++) {
  p = mat[flag][i];
  mat[flag][i] = NULL;
  while (p != NULL) {
    q = p->next;
    free( p);
    p = q;
  }
}

}

int MATRalive (int x, int y, int flag)
{
cell_t *p;

p = mat[flag][x];
while ((p != NULL) && (p->y < y))
  p = p->next;

if ((p != NULL) && (p->y == y))
  return (1);
else
  return (0);

}



