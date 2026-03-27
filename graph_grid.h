//
// Created by isabe on 3/25/2026.
//

#ifndef UNTITLED3_GRAPH_GRID_H
#define UNTITLED3_GRAPH_GRID_H
#include <stdint.h>
#define MAX_NODES 15
#include "priority_queue.h"
#include "dispatch.h"

typedef struct Edge{
    int to;
    int weight;//distance in meters
    struct Edge* next;
} Edge;

typedef struct {
    //all the adjacent nodes (adjacency list)
    Edge* adjacentNodes[MAX_NODES];
    int numNodes;
    Incident* occupiedIncident[MAX_NODES];
    DispatchUnit* occupiedDispatch[MAX_NODES];
} Graph ;

enum intersectionNames {
    KING_LOWERALBERT,
    COLLINGWOOD_KING,
    COLLINGWOOD_QUEENSCRESENT,
    QUEENSCRESENT_ALBERT,
    ALBERT_STUART_LOWERALBERT,
    STUART_UNIVERSITY,
    STUART_ARCH,
    UNION_DIVISION,
    DIVISION_EARL,
    EARL_UNIVERSITY,
    UNION_UNIVERSITY,
    UNION_FONTENAC,
    FONTENAC_EARL,
    ALBERT_UNION,
    UNION_ARCH

};

void printIntersections();
void createGraph(Graph* graph, int nodes);
void addEdge(Graph* graph, int from, int to, int weight);
void printGraph(Graph* g);
#endif //UNTITLED3_GRAPH_GRID_H