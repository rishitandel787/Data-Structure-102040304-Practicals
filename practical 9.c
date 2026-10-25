#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum number of vertices in the graph

// Graph representation using an Adjacency Matrix
int adj[MAX][MAX];
int visited[MAX];

// Queue implementation for BFS
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    int vertex = queue[front++];
    if (front > rear) {
        front = rear = -1; // Reset queue when empty
    }
    return vertex;
}

int isQueueEmpty() {
    return front == -1;
}

// ==================== BREADTH-FIRST SEARCH (BFS) ====================
void bfs(int startVertex, int numVertices) {
    // Reset visited array for BFS
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    printf("BFS Traversal starting from vertex %d: ", startVertex);

    visited[startVertex] = 1;
    enqueue(startVertex);

    while (!isQueueEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        // Visit all adjacent unvisited vertices
        for (int i = 0; i < numVertices; i++) {
            if (adj[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

// ==================== DEPTH-FIRST SEARCH (DFS) ====================
void dfs(int currentVertex, int numVertices) {
    printf("%d ", currentVertex);
    visited[currentVertex] = 1;

    // Visit all adjacent unvisited vertices recursively
    for (int i = 0; i < numVertices; i++) {
        if (adj[currentVertex][i] == 1 && !visited[i]) {
            dfs(i, numVertices);
        }
    }
}

void startDfs(int startVertex, int numVertices) {
    // Reset visited array for DFS
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal starting from vertex %d: ", startVertex);
    dfs(startVertex, numVertices);
    printf("\n");
}

int main() {
    int numVertices = 5;

    // Initialize adjacency matrix to 0
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adj[i][j] = 0;
        }
    }

    /* 
       Constructing an undirected graph with 5 vertices (0 to 4):
       Edges:
       0 - 1
       0 - 2
       1 - 3
       1 - 4
       2 - 4
    */
    
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[1][4] = adj[4][1] = 1;
    adj[2][4] = adj[4][2] = 1;

    printf("=== Graph Traversal (BFS & DFS) Demonstration ===\n\n");

    // Perform BFS starting from vertex 0
    bfs(0, numVertices);

    // Perform DFS starting from vertex 0
    startDfs(0, numVertices);

    return 0;
}
