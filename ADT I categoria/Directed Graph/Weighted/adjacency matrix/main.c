#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ts.h"
#include "Graph.h"

/********************************************************************
  DEFINIZIONE STRUTTURA DATI E COSTANTI
********************************************************************/

#define SUCCESS         1
#define FAILURE         2
#define MAX_LEN        21

/********************************************************************
  PROTOTIPI
********************************************************************/

Graph graph_read(FILE *fin, TS nodes, int n_nodes);
TS TS_read(FILE *fin, int n_edges);

/********************************************************************
  Funzione di lettura (grafo): carica le informazioni in
  una struttura di tipo grafo.
********************************************************************/
Graph graph_read(FILE *fin, TS nodes, int n_nodes)
{
   char name1[MAX_LEN], name2[MAX_LEN];
   int ew, src, dst;
   Graph graph;

   graph = GRAPHinit(n_nodes);

   while (fscanf(fin, "%s %d %s", name1, &ew, name2) != EOF) {
     src = TScerca(nodes, name1);
     dst = TScerca(nodes, name2);
     if (src == -1 || dst == -1) {
	   printf("Errore di inserzione nel grafo\n");
	   fclose(fin);
       exit(FAILURE);
     }
     GRAPHInsertE(graph, src, dst, ew);
   }

   return graph;
}

/********************************************************************
  Funzione di lettura del file (lista di città): carica tutte le
  informazioni in una symbol table
********************************************************************/
TS TS_read(FILE *fin, int n_edge)
{
   TS st = NULL;
   char name1[MAX_LEN], name2[MAX_LEN];
   int i, w;

   st = TScrea(2*n_edge);

   for(i=0;i<n_edge;i++) {
      fscanf(fin, "%s %d %s", name1, &w, name2);
      TSaggiungi(st,name1);
      TSaggiungi(st,name2);
   }
   return st;
}

/********************************************************************
  MAIN
********************************************************************/
int main (void)
{
   char fname[MAX_LEN], node1[MAX_LEN], node2[MAX_LEN];
   Graph graph = NULL;
   TS nodes = NULL;
   int w, idx, n_edges = 0, n_nodes;

   printf("Nome del file di ingresso che contiene un grafo orientato, pesato, semplice: ");
   scanf("%s", fname);

   FILE *fin;
   fin = fopen(fname, "r");
   if (fin == NULL) {
      printf("Errore di apertura file %s\n", fname);
      exit(FAILURE);
   }

   while (fscanf(fin, "%s %d %s", node1, &w, node2) != EOF) {
      n_edges++;
   }
   printf("numero di archi grafo= %d\n", n_edges);

   fclose(fin);

   fin = fopen(fname, "r");
   if (fin == NULL) {
      printf("Errore di apertura file %s\n", fname);
      exit(FAILURE);
   }

   nodes = TS_read(fin, n_edges);
   if (nodes == NULL)
      return FAILURE;
   n_nodes = TSdimensione(nodes);
   printf("dimensione della TS= %d\n", n_nodes);

   fclose(fin);

   fin = fopen(fname, "r");
   if (fin == NULL) {
      printf("Errore di apertura file %s\n", fname);
      exit(FAILURE);
   }

   graph = graph_read(fin, nodes, n_nodes);
   if (graph == NULL)
      return FAILURE;

   fclose(fin);

   GRAPHshow(graph, nodes);

   printf("Nodo di partenza: ");
   scanf("%s", node1);
   idx = TScerca(nodes, node1);

   if (idx >= 0)
   {
     printf("Tutti i cammmini semplici da %s \n", node1);
     GRAPHallsimplepaths(graph, nodes, idx);
   }
   else
      printf("Errore: nodo non trovato!\n");


   GRAPHfree(graph);
   TSlibera(nodes);

   return SUCCESS;
}
