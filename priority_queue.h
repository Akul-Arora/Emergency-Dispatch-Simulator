#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

// ─────────────────────────────────────────────
//  Incident definition (shared across files)
// ─────────────────────────────────────────────
typedef struct {
    int id;
    int severity;       // 1 (low) to 5 (critical)
    int location;       // graph node id
    int requiredType;   // 1=ambulance 2=fire 3=police
    int timeReported;   // simulation tick when reported
} Incident;

//  Priority Queue Node (singly linked list)
typedef struct PQNode {
    Incident data;
    struct PQNode* next;
} PQNode;

//  Priority Queue (head = highest priority)
typedef struct {
    PQNode* head;
    int size;
} PriorityQueue;

// Setting up an empty queue
void pq_init(PriorityQueue* pq);

/* Insert an incident in priority order (highest severity first).
   Ties broken by timeReported: earlier report = higher priority */
void pq_enqueue(PriorityQueue* pq, Incident inc);

/* Remove and return the highest-priority incident.
   Caller must check pq_is_empty() first! */
Incident pq_dequeue(PriorityQueue* pq);

//Peek at the highest-priority incident without removing it
Incident pq_peek(PriorityQueue* pq);

// Returns 1 if empty, 0 otherwise 
int pq_is_empty(PriorityQueue* pq);

// Print all incidents in the queue (for debugging/output)
void pq_print(PriorityQueue* pq);

//Free all memory in the queue
void pq_free(PriorityQueue* pq);

#endif