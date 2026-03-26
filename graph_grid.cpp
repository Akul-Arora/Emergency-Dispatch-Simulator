//
// Created by isabe on 3/25/2026.
//

#include "graph_grid.h"
#include <stdio.h>
#include <stdlib.h>
void createGraph(Graph* graph, int8_t nodes) {
    graph->numNodes = nodes;
    for (int i = 0; i < nodes; i++) {
        graph->adjacentNodes[i] = NULL;
    }
}
//maybe also add in char for streetnname ask group
void addEdge(Graph* graph, int8_t from, uint8_t to, uint8_t weight) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->to = to;
    edge->weight = weight;
    edge->next = graph->adjacentNodes[from];
    graph->adjacentNodes[from] = edge;

    Edge* edge2 = (Edge*)malloc(sizeof(Edge));
    edge2->to = from;
    edge2->weight = weight;
    edge2->next = graph->adjacentNodes[to];
    graph->adjacentNodes[to] = edge2;
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->numNodes; i++) {
        printf("Node %d -> ", i);

        Edge* temp = g->adjacentNodes[i];
        while (temp) {
            printf("[%d,w=%d] ", temp->to, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}