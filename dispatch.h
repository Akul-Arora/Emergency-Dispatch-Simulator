#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priority_queue.h"
#define MAX_INCIDENTS 100
#define MAX_UNITS 10
#include "graph_grid.h"


// Dispatch unit structure
typedef struct {
    int id;
    int type;              // 1=ambulance 2=fire 3=police
    int location;
    int available;         // 1 = available, 0 = busy
}
DispatchUnit;

void initializeUnits();
Incident createIncident(Graph *g);
void addIncident(PriorityQueue *pq);
void dispatchUnit(Incident inc);
void dijkstra(Graph* graph, int src, int dist[], int parent[] );
void Time();
int getTime();

