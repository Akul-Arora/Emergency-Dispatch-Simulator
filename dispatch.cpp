#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priority_queue.h"

#define MAX_INCIDENTS 100
#define MAX_UNITS 10

// Dispatch unit structure
typedef struct {
    int id;
    int type;              // 1=ambulance 2=fire 3=police
    int location;
    int available;         // 1 = available, 0 = busy
} DispatchUnit;

Incident incidents[MAX_INCIDENTS];
int incidentCount = 0;

DispatchUnit units[MAX_UNITS];
int unitCount = 0;

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

void addIncident() {

    if (incidentCount >= MAX_INCIDENTS) {
        printf("Incident storage full.\n");
        return;
    }

    Incident inc = createIncident();

    incidents[incidentCount] = inc;
    incidentCount++;

    printf("Incident added successfully.\n");
}

void dispatchUnit(Incident inc) {

    for (int i = 0; i < unitCount; i++) {

        if (units[i].type == inc.requiredType && units[i].available == 1) {

            printf("Dispatching Unit %d to Incident %d\n",
                   units[i].id, inc.id);

            units[i].available = 0;
            return;
        }
    }

    printf("No available units for this incident.\n");
}

int main() {

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
    }

    return 0;
}
