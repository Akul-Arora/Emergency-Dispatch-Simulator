#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dispatch.h"
#include "graph_grid.h"
#include "priority_queue.h"

#define MAXNODES 50
#define INF 1000000000


int idInc = 0;
int simtime=0;
Incident incidents[MAX_INCIDENTS];
int incidentCount = 0;

DispatchUnit units[MAX_UNITS];
int unitCount = 0;

void Time() {
    simtime++;
}
int getTime() {
    return simtime;
}

PriorityQueue pq;

void initializeUnits() {
    unitCount = 3;

    units[0].id = 1;
    units[0].type = 1; // ambulance
    units[0].location = 0;
    units[0].available = 1;

    units[1].id = 2;
    units[1].type = 2; // fire
    units[1].location = 3;
    units[1].available = 1;

    units[2].id = 3;
    units[2].type = 3; // police
    units[2].location = 5;
    units[2].available = 1;
}

Incident createIncident(Graph* g) {
    Incident incident;
    idInc++;
    incident.id = idInc;

    printf("What type of dispatch do you need.\n Type 1 for ambulance, 2 for fire, and 3 for police");
    scanf("%d", (int*)&incident.requiredType);

    printf("What is the severity from 1-5.\n");
    scanf("%d", (int*)&incident.severity);


    printf("What is the intersection location of the incident please put in a number 0-14 based on the intersections provided below.\n");
    printIntersections();
    scanf("%d", &incident.location);

    incident.timeReported = idInc;
    g->occupiedIncident[incident.location] = &incident;
    return incident;
}

void addIncident(PriorityQueue* pq) {

    if (incidentCount >= MAX_INCIDENTS) {
        printf("Incident storage full.\n");
        return;
    }

    Incident inc = createIncident();


    incidents[incidentCount] = inc;
    incidentCount++;
    pq_enqueue(pq, inc);
    Time();



    printf("Incident added successfully.\n");
}

void dispatchUnit(Graph* graph, Incident inc) {

    /*for (int i = 0; i < unitCount; i++) {

        if (units[i].type == inc.requiredType && units[i].available == 1) {

            printf("Dispatching Unit %d to Incident %d\n",
                   units[i].id, inc.id);

            units[i].available = 0;
            Time();
            return;
        }
    }*/
    DispatchUnit* best = findBestUnit(graph, inc);

    if (best != NULL) {

        printf("Dispatching Unit %d to Incident %d\n",
               best->id, inc.id);

        best->available = 0;
        Time();
    } else {
        printf("No available units → incident delayed\n");

        pq_enqueue(&pq, inc);
    }
    //printf("No available units for this incident.\n");
}

void dijkstra(Graph* graph, int src, int dist[], int parent[]) {
    int visited[MAXNODES] = {0};//0 rep not visited yet and 1 rep already chosen and processed

    // Initialize
    // go through every node in the grauph and init its values
    for (int i = 0; i < graph->numNodes; i++) {
        dist[i] = INF;//assume every node is far far away
        parent[i] = -1;//no node has a previous node on the shortest path rn
    }

    dist[src] = 0;// the distance from the source to itself is 0

    // Main loop
    for (int i = 0; i < graph->numNodes; i++) {
        // repet per node
        // 111: pick the closet unvisited node
        // 222: mark it visited
        // 333: update its neighbor


        // Find unvisited node with smallest distance
        int u = -1; // hold node num
        int minDist = INF; // store the smallest dist found so far

        //look through nodes: skip visited node;
        for (int j = 0; j < graph->numNodes; j++) {
            if (!visited[j] && dist[j] < minDist) {//If node j is unvisited and has the smallest distance seen so far
                // WE FOUND A BETTER NEXT NODE !!! :)
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break; // no reachable nodes left

        // we are done finding the shortest distance to u
        visited[u] = 1;  // visited

       // Relax edges
       //start at the first edge of node u
       //keep going while e != NULL
       //move to next
        for (Edge* e = graph->adjacentNodes[u]; e != NULL; e = e->next) {
            int v = e->to;
            int nd = dist[u] + e->weight;

            if (nd < dist[v]) {
                dist[v] = nd;
                parent[v] = u;
            }
        }
    }
}

DispatchUnit* findBestUnit(Graph* graph, Incident inc) {

    int dist[MAXNODES];
    int parent[MAXNODES];

    DispatchUnit* best = NULL;
    int bestDist = INF;

    for (int i = 0; i < unitCount; i++) {
        if (units[i].type == inc.requiredType && units[i].available){
            dijkstra(graph, units[i].location, dist, parent);

            int d = dist[inc.location];

            if (d < bestDist) {
                bestDist = d;
                best = &units[i];
            }
        }
    }
    return best;
}