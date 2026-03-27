#include <iostream>
#include "graph_grid.h"
#include "dispatch.h"
#include "priority_queue.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Graph g;
    createGraph(&g, 15);
    addEdge(&g, 3, 4, 140);
    addEdge(&g, 3, 2, 250);
    addEdge(&g, 2, 1, 120);
    addEdge(&g, 1, 5, 130);
    addEdge(&g, 5, 4, 120);
    addEdge(&g, 5, 6, 330);
    addEdge(&g, 6, 11, 410);
    addEdge(&g, 4, 14, 290);
    addEdge(&g, 14, 12, 130);
    addEdge(&g, 12, 11, 220);
    addEdge(&g, 12, 13, 250);
    addEdge(&g, 13, 10, 230);
    addEdge(&g, 11, 10, 220);
    addEdge(&g, 11, 8, 210);
    addEdge(&g, 10, 9, 210);
    addEdge(&g, 9, 8, 220);
    addEdge(&g, 8, 15, 90);
    addEdge(&g, 15, 7, 320);
    addEdge(&g, 6, 7, 320);
    printf("Queen's University Road Network");
    printGraph(&g);

    initializeUnits();
    PriorityQueue incidentQueue;
    pq_init(&incidentQueue);

    int choice;
    int incidentCount = 0;

    while (true) {
        printf("\n--- Emergency Dispatch System ---\n");
        printf("1. Add Incident\n");
        printf("2. Exit\n");

        scanf("%d", &choice);

        if (choice == 1) {
            addIncident(&incidentQueue);

        }
        else if (choice == 2) {
            if (pq_is_empty(&incidentQueue)) {
                printf("No incidents available");

            }
            else {
                Incident top=pq_dequeue(&incidentQueue);
                dispatchUnit(top);
            }

        }
        else if (choice==3) {
            printf("\nCurrent Incident Queue\n");
            pq_print(&incidentQueue);
        }
        else if (choice==4) {
            printf("Shutting down dispatch system");

        }
        else
                printf("Invalid Choice");

    }

    return 0;
}