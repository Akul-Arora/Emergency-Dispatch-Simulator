#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INCIDENTS 100
#define MAX_UNITS 10

// Incident structure
typedef struct {
    int id;
    int severity;          // 1-5
    int location;          // node id
    int requiredType;      // 1=ambulance 2=fire 3=police
    int timeReported;
} Incident;

// Dispatch unit structure
typedef struct {
    int id;
    int type;              // 1=ambulance 2=fire 3=police
    int location;
    int available;         // 1 = available, 0 = busy
} DispatchUnit;

void initializeUnits();

Incident createIncident() ;

void addIncident();

void dispatchUnit(Incident inc);

