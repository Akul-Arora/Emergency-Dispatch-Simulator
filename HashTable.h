//
// Created by isabe on 3/26/2026.
//

#ifndef UNTITLED3_HASHTABLE_H
#define UNTITLED3_HASHTABLE_H
#include "dispatch.h"
#include "graph_grid.h"
#include "priority_queue.h"
#define TABLE_SIZE 100

typedef struct Entry {
    int key;
    void *information;
    struct Entry *next;
} Entry;

typedef struct {
    Entry *buckets[TABLE_SIZE];
} HashTable;

int hash(int key);

typedef enum {
    INCIDENT_ACTIVE,
    INCIDENT_HANDLED
} IncidentStatus;

typedef enum {
    DISPATCH_FREE,
    DISPATCH_INUSE
} DispatchStatus;
#endif //UNTITLED3_HASHTABLE_H