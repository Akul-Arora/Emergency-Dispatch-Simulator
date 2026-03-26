#include <iostream>
#include "graph_grid.h"
#include "dispatch.h"
#include "priority_queue.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Graph g;
    createGraph(&g, 15);
//to make them fit into size they are 1/10 of a km as weight
    addEdge(&g, 3, 4, 14);
    addEdge(&g, 3, 2, 25);
    addEdge(&g, 2, 1, 12);
    addEdge(&g, 1, 5, 13);
    addEdge(&g, 5, 4, 12);
    addEdge(&g, 5, 6, 33);
    addEdge(&g, 6, 11, 41);
    addEdge(&g, 4, 14, 29);
    addEdge(&g, 4, 14, 29);
    addEdge(&g, 14, 12, 13);
    addEdge(&g, 12, 11, 22);
    addEdge(&g, 12, 13, 25);
    addEdge(&g, 13, 10, 23);
    addEdge(&g, 11, 10, 22);
    addEdge(&g, 11, 8, 21);
    addEdge(&g, 10, 9, 21);
    addEdge(&g, 9, 8, 22);
    addEdge(&g, 8, 15, 9);
    addEdge(&g, 15, 7, 32);
    addEdge(&g, 6, 7, 32);

    printGraph(&g);

        initializeUnits();

        int choice;

        while (1) {

            printf("\n--- Emergency Dispatch System ---\n");
            printf("1. Add Incident\n");
            printf("2. Dispatch Last Incident\n");
            printf("3. Exit\n");

            scanf("%d", &choice);

            if (choice == 1) {

                addIncident();

            } else if (choice == 2) {

                if (incidentCount == 0) {
                    printf("No incidents available.\n");
                } else {

                    dispatchUnit(incidents[incidentCount - 1]);
                }

            } else if (choice == 3) {

                break;
            }

    return 0;    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}