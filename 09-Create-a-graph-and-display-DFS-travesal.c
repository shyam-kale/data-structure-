#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int vertices;
};

void initGraph(struct Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            g->adjMatrix[i][j] = 0;
}

void addEdge(struct Graph* g, int start, int end) {
    g->adjMatrix[start][end] = 1;
    g->adjMatrix[end][start] = 1; // Since it's an undirected graph
}

void DFS(struct Graph* g, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Explore all the unvisited adjacent vertices
    for (int i = 0; i < g->vertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(g, i, visited);
        }
    }
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

    int visited[MAX_VERTICES] = {0};

    printf("Enter start vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS: ");
    DFS(&g, start, visited);
    printf("\n");

    return 0;
}
