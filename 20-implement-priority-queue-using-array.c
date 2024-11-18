#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the priority queue

// Define the structure for Priority Queue
struct PriorityQueue {
    int items[MAX];
    int priority[MAX];
    int size;
};

// Function to initialize the priority queue
void initializeQueue(struct PriorityQueue* pq) {
    pq->size = 0;
}

// Function to check if the queue is full
int isFull(struct PriorityQueue* pq) {
    return pq->size == MAX;
}

// Function to check if the queue is empty
int isEmpty(struct PriorityQueue* pq) {
    return pq->size == 0;
}

// Function to enqueue (add element with priority)
void enqueue(struct PriorityQueue* pq, int value, int prio) {
    if (isFull(pq)) {
        printf("Priority Queue is full. Cannot enqueue %d.\n", value);
        return;
    }

    // Insert element in the last position
    int i = pq->size - 1;
    while (i >= 0 && pq->priority[i] < prio) {
        pq->items[i + 1] = pq->items[i];
        pq->priority[i + 1] = pq->priority[i];
        i--;
    }

    pq->items[i + 1] = value;
    pq->priority[i + 1] = prio;
    pq->size++;
    printf("Enqueued %d with priority %d.\n", value, prio);
}

// Function to dequeue (remove element with highest priority)
void dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return;
    }

    int dequeuedValue = pq->items[0];
    printf("Dequeued %d with priority %d.\n", dequeuedValue, pq->priority[0]);

    // Shift elements left
    for (int i = 0; i < pq->size - 1; i++) {
        pq->items[i] = pq->items[i + 1];
        pq->priority[i] = pq->priority[i + 1];
    }

    pq->size--;
}

// Function to display the priority queue
void displayQueue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue contents:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Value: %d, Priority: %d\n", pq->items[i], pq->priority[i]);
    }
}

int main() {
    struct PriorityQueue pq;
    initializeQueue(&pq);

    int choice, value, prio;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                printf("Enter priority of the element: ");
                scanf("%d", &prio);
                enqueue(&pq, value, prio);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                displayQueue(&pq);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
