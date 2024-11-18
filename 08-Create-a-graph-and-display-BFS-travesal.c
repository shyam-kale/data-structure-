#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

struct Queue {
    int items[MAX_VERTICES];
    int front, rear;
};

struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int vertices;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isQueueEmpty(q)) return -1;
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) q->front = q->rear = -1;
    return item;
}

void initGraph(struct Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            g->adjMatrix[i][j] = 0;
}

void addEdge(struct Graph* g, int start, int end) {
    g->adjMatrix[start][end] = 1;
    g->adjMatrix[end][start] = 1;
}

void BFS(struct Graph* g, int start) {
    struct Queue q;
    initQueue(&q);
    int visited[MAX_VERTICES] = {0};
    visited[start] = 1;
    enqueue(&q, start);

    printf("BFS: ");
    while (!isQueueEmpty(&q)) {
        int vertex = dequeue(&q);
        printf("%d ", vertex);
        for (int i = 0; i < g->vertices; i++) {
            if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    struct Graph g;
    int vertices, edges, start, v1, v2;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (start end): ");
        scanf("%d %d", &v1, &v2);
        addEdge(&g, v1, v2);
    }

    printf("Enter start vertex for BFS: ");
    scanf("%d", &start);
    BFS(&g, start);

    return 0;
}
