//
// Created by isabe on 3/25/2026.
//

#ifndef UNTITLED3_GRAPH_GRID_H
#define UNTITLED3_GRAPH_GRID_H
#include <stdint.h>
#define MAX_NODES 14

typedef struct Edge{
    uint8_t to;
    uint8_t weight;//distance in meters
    struct Edge* next;
} Edge;

typedef struct {
    //all the adjacent nodes (adjacency list)
    Edge* adjacentNodes[MAX_NODES];
    uint8_t numNodes;
    uint8_t occupied[MAX_NODES];
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
void createGraph(Graph* graph, int8_t nodes);
void addEdge(Graph* graph, int8_t from, uint8_t to, uint8_t weight);
void printGraph(Graph* g);
static void dijkstra(int src, int dist[], int parent[]);
static void print_path(int src, int dst, int parent[]);
#endif //UNTITLED3_GRAPH_GRID_H