typedef struct { int v; int w; } Edge;
Edge EDGE(int, int);

typedef struct dag *Dag;

Dag   DAGinit(int);
void  DAGinsertE(Dag, Edge);
void  DAGremoveE(Dag, Edge);
int   DAGedges(Edge [], Dag D);
void  DAGshow(Dag D);
void  DAGrts(Dag D);

