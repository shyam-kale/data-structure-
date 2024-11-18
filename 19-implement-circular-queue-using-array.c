#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the circular queue

// Define the structure for Circular Queue
struct CircularQueue {
    int items[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initializeQueue(struct CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct CircularQueue* q) {
    if ((q->rear + 1) % MAX == q->front) {
        return 1;  // Queue is full
    }
    return 0;  // Queue is not full
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* q) {
    if (q->front == -1) {
        return 1;  // Queue is empty
    }
    return 0;  // Queue is not empty
}

// Function to add an element to the queue (enqueue)
void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    if (q->front == -1) {  // If the queue is empty
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;  // Circular increment
    q->items[q->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

// Function to remove an element from the queue (dequeue)
void dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("%d dequeued from the queue.\n", q->items[q->front]);
    if (q->front == q->rear) {  // Only one element in the queue
        q->front = q->rear = -1;  // Reset the queue
    } else {
        q->front = (q->front + 1) % MAX;  // Circular increment
    }
}

// Function to display the elements of the queue
void displayQueue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;  // Circular increment
    }
    printf("%d\n", q->items[q->rear]);  // Print the rear element
}

int main() {
    struct CircularQueue q;
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
