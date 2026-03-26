#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dispatch.h"


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

Incident createIncident() {
    Incident incident;
    printf("Hello it is 911 dispatch\nWhat is the ID.\n");
    scanf("%d", (int*)&incident.id);

    printf("What type of dispatch do you need.\n Type 1 for ambulance, 2 for fire, and 3 for police");
    scanf("%d", (int*)&incident.requiredType);

    printf("What is the ID.\n");
    scanf("%d", (int*)&incident.id);

    printf("What is the ID.\n");
    scanf("%d", (int*)&incident.id);

    printf("What is the ID.\n");
    scanf("%d", (int*)&incident.id);
    return incident;
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