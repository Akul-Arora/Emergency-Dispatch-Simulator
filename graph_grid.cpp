//
// Created by isabe on 3/25/2026.
//

#include "graph_grid.h"
#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "dispatch.h"
void createGraph(Graph* graph, int nodes) {
    graph->numNodes = nodes;
    for (int i = 0; i < nodes; i++) {
        graph->adjacentNodes[i] = NULL;
        graph->occupiedDispatch[i] = NULL;
        graph->occupiedIncident[i] = NULL;
    }
}
//maybe also add in char for streetnname ask group
void addEdge(Graph* graph, int from, int to, int weight) {
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

void printIntersections() {
    for (int i = KING_LOWERALBERT; i <= UNION_ARCH; i++) {
        printf("%d - ", i);

        switch(i) {
            case KING_LOWERALBERT:
                printf("Intersection of King and Lower Albert\n");
                break;
            case COLLINGWOOD_KING:
                printf("Intersection of Collingwood and King\n");
                break;
            case COLLINGWOOD_QUEENSCRESENT:
                printf("Intersection of Collingwood and Queens Crescent\n");
                break;
            case QUEENSCRESENT_ALBERT:
                printf("Intersection of Queens Crescent and Albert\n");
                break;
            case ALBERT_STUART_LOWERALBERT:
                printf("Intersection of Albert, Stuart, and Lower Albert\n");
                break;
            case STUART_UNIVERSITY:
                printf("Intersection of Stuart and University\n");
                break;
            case STUART_ARCH:
                printf("Intersection of Stuart and Arch\n");
                break;
            case UNION_DIVISION:
                printf("Intersection of Union and Division\n");
                break;
            case DIVISION_EARL:
                printf("Intersection of Division and Earl\n");
                break;
            case EARL_UNIVERSITY:
                printf("Intersection of Earl and University\n");
                break;
            case UNION_UNIVERSITY:
                printf("Intersection of Union and University\n");
                break;
            case UNION_FONTENAC:
                printf("Intersection of Union and Fontenac\n");
                break;
            case FONTENAC_EARL:
                printf("Intersection of Fontenac and Earl\n");
                break;
            case ALBERT_UNION:
                printf("Intersection of Albert and Union\n");
                break;
            case UNION_ARCH:
                printf("Intersection of Union and Arch\n");
                break;
            default:
                printf("Unknown intersection\n");
        }
    }
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