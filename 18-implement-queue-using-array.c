#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

// Define the queue structure
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    if (q->rear == MAX - 1) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

// Function to add an element to the queue (enqueue)
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0; // If the queue is empty, set front to 0
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

// Function to remove an element from the queue (dequeue)
void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("%d dequeued from the queue.\n", q->items[q->front]);
    // Shift all elements to the left
    for (int i = 0; i < q->rear; i++) {
        q->items[i] = q->items[i + 1];
    }
    q->rear--;
    if (q->rear == -1) {
        q->front = -1; // If the queue is empty after dequeue
    }
}

// Function to display the elements of the queue
void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initializeQueue(&q);

    int choice, value;

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
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayQueue(&q);
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
