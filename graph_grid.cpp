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
        graph->occupied[i] = 0;
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

static void dijkstra(int src, int dist[], int parent[]) {
    for (int i = 0; i < N; i++) {
        dist[i] = INF;//shortest distance currently known from source to node i
        //dist[3] = 0 from source to 3 costs 0

        parent[i] = -1;//which previous node gave the best path to i
        //if shortest path to 11 comes from 14  parent[11] = 14
    }
    dist[src] = 0;

    MinHeap h;
    h.sz = 0;
    heap_push(&h, src, 0);

    while (!heap_empty(&h)) {
        HeapItem cur = heap_pop(&h);
        int u = cur.node;
        int d = cur.dist;

        if (d != dist[u]) continue; /* stale heap item */

        for (Edge *e = g[u]; e; e = e->next) {
            int v = e->to;
            int nd = d + e->w;
            if (nd < dist[v]) {
                dist[v] = nd;
                parent[v] = u;
                heap_push(&h, v, nd);
            }
        }
    }
}

static void print_path(int src, int dst, int parent[]) {
    if (src == dst) {
        printf("%d", src);
        return;
    }
    if (parent[dst] == -1) {
        printf("(no path)");
        return;
    }

    int stack[MAXN], top = 0;
    int cur = dst;
    while (cur != -1) {
        stack[top++] = cur;
        if (cur == src) break;
        cur = parent[cur];
    }
    if (stack[top - 1] != src) {
        printf("(no path)");
        return;
    }

    for (int i = top - 1; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i) printf(" -> ");
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