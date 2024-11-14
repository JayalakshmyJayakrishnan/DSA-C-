#include <stdio.h>

#define MAX 10

// Graph represented as an adjacency matrix
int graph[MAX][MAX];
int visited[MAX];
int queue[MAX], front = -1, rear = -1;

// Add an edge to the graph
void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1; // For an undirected graph
}

// BFS function
void bfs(int start, int n) {
    front = rear = 0;
    queue[rear] = start;
    visited[start] = 1;
    
    printf("BFS traversal: ");
    while (front <= rear) {
        int node = queue[front++];
        printf("%d ", node);
        
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, edges, u, v, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize graph and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Add edges
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Input start node for traversal
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    // Perform BFS traversal
    bfs(start, n);

    return 0;
}
