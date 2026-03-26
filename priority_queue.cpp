#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

/*pq_init
Sets up an empty queue. Always call this first.*/
void pq_init(PriorityQueue* pq) {
    pq->head = NULL;
    pq->size = 0;
}

/*pq_enqueue
   Inserts an incident into the correct position
   so the list stays sorted: highest severity at
   the front. Ties broken by timeReported (earlier
   reports go first — cuz like they've waited longer).*/
void pq_enqueue(PriorityQueue* pq, Incident inc) {

    // Allocate a new node
    PQNode* newNode = (PQNode*)malloc(sizeof(PQNode));
    if (newNode == NULL) {
        printf("ERROR: Memory allocation failed in pq_enqueue.\n");
        return;
    }
    newNode->data = inc;
    newNode->next = NULL;

    // Case 1: Queue is empty OR new incident has higher/equal priority than head
    if (pq->head == NULL ||
        inc.severity > pq->head->data.severity ||
        (inc.severity == pq->head->data.severity &&
         inc.timeReported < pq->head->data.timeReported)) {

        newNode->next = pq->head;
        pq->head = newNode;
        pq->size++;
        return;
    }

    // Case 2: go through the list to find the right insertion spot
    PQNode* current = pq->head;
    while (current->next != NULL) {
        int nextSeverity     = current->next->data.severity;
        int nextTimeReported = current->next->data.timeReported;
        // Stop if the next node has lower priority than the new incident
        if (inc.severity > nextSeverity ||
            (inc.severity == nextSeverity && inc.timeReported < nextTimeReported)) {
            break;
        }
        current = current->next;
    }
    // Insert newNode between current and current->next
    newNode->next  = current->next;
    current->next  = newNode;
    pq->size++;
}

/*
   pq_dequeue
   Removes and returns the highest-priority
   incident (always the head of the list).
   Check pq_is_empty() before calling this! */
Incident pq_dequeue(PriorityQueue* pq) {

    if (pq_is_empty(pq)) {
        printf("ERROR: Attempted to dequeue from an empty queue.\n");
        // Return a blank incident so the program doesn't crash
        Incident empty = {-1, 0, 0, 0, 0};
        return empty;
    }

    PQNode*  topNode = pq->head;
    Incident topData = topNode->data;

    pq->head = pq->head->next;  // Move head forward
    free(topNode);              // Free the old head
    pq->size--;

    return topData;
}

/*pq_peek
   Returns the highest-priority incident WITHOUT
   removing it. Check pq_is_empty() first! */
Incident pq_peek(PriorityQueue* pq) {

    if (pq_is_empty(pq)) {
        printf("ERROR: Attempted to peek into an empty queue.\n");
        Incident empty = {-1, 0, 0, 0, 0};
        return empty;
    }

    return pq->head->data;
}

/*pq_is_empty
   Returns 1 if the queue has no incidents, 0 if
   it does. Use this before dequeue/peek.*/
int pq_is_empty(PriorityQueue* pq) {
    return pq->head == NULL;
}

/* pq_print
   Prints every incident in the queue from
   highest to lowest priority. Good for your
   simulation output and debugging.*/
void pq_print(PriorityQueue* pq) {

    if (pq_is_empty(pq)) {
        printf("  [Priority Queue is empty]\n");
        return;
    }

    printf("  Priority Queue (high -> low):\n");

    PQNode* current = pq->head;
    int rank = 1;

    while (current != NULL) {
        Incident* inc = &current->data;

        // Map type int to a readable string
        const char* typeName = "Unknown";
        if      (inc->requiredType == 1) typeName = "AMBULANCE";
        else if (inc->requiredType == 2) typeName = "FIRE";
        else if (inc->requiredType == 3) typeName = "POLICE";

        printf("  [%d] ID:%-3d | Severity:%d | Type:%-10s | Node:%-2d | Reported:t%d\n",
               rank,
               inc->id,
               inc->severity,
               typeName,
               inc->location,
               inc->timeReported);

        current = current->next;
        rank++;
    }
}

/* pq_free
   Frees all nodes in the queue. Call this at
   the end of your program to avoid memory leaks.*/
void pq_free(PriorityQueue* pq) {
    while (!pq_is_empty(pq)) {
        pq_dequeue(pq); // dequeue already calls free() on each node
    }
}