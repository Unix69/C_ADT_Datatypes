/*****************************************************************************

				LIFE.C

******************************************************************************/

#include <stdio.h>

#include "matr.h"

#define MAX 10

int	a[8]={0, 1, 1, 1, 0, -1, -1, -1},
	b[8]={1, 1, 0, -1, -1, -1, 0, 1};

int readfile (FILE *fp, int flag);
int insert (int x, int y, int flag);
int update (int flag);
int neighbour (int x, int y, int flag);


int main (int argc, char *argv[])
{
FILE	*fin;
int	flag=0;
int	step=0;

if (argc < 2) {
  printf ("ERRORE - uso corretto:\n%s ,<nomefile>\n", argv[0]);
  return (1);
}

if ((fin=fopen(argv[1],"r")) == NULL) {
  printf( "Errore in apertura file %s\n", argv[1]);
  return (1);
}

if (!readfile (fin, flag)) {
  printf ("Errore in lettura file %s\n", argv[1]);
  return (1);
}

fclose (fin);

while (update(flag) && (step++<MAX))
  flag = !flag;

printf( "Numero generazioni: %d\n", step);

}








int readfile( FILE *fp, int flag)
{
int x, y, i;

for (i=0; fscanf (fp, "%d %d", &x, &y) > 0; i++)
  if( !MATRinsert( x, y, flag)) {
    printf( "Errore in inserimento cella %d %d\n", x, y);
    return( 0);
  }

return (1);
}


int update (int flag)
{
int i, j, n, count=0;

for (i=0; i<MAXR; i++)
  for (j=0; j<MAXC; j++)
    if (MATRalive( i, j, flag)) {
      if (((n = neighbour (i, j, flag)) == 2) || (n == 3)) {
	if (!MATRinsert (i, j, !flag)) {
	  printf( "Errore in creazione nuovo organismo %d %d\n", i, j);
	  return( 0);
	}
      }
      else
	count++;
    }
    else {
      if (neighbour (i, j, flag) == 3) {
	if (!MATRinsert (i, j, !flag)) {
	  printf( "Errore in creazione nuovo organismo %d %d\n", i, j);
	  return( 0);
	}
	count++;
      }
    }

MATRreset (flag);

return( count);

}

int neighbour (int x, int y, int flag)
{
int i, xx, yy, count=0;

for (i=0; i<8; i++) {
  xx = x + a[i];
  yy = y + b[i];
  if (xx >= 0 && xx < MAXR && yy >= 0 && yy < MAXC)
    if (MATRalive( xx, yy, flag))
      count++;
}

return( count);

}



