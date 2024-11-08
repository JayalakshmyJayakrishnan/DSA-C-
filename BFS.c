#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
void bfs(int startVertex, int vertices) {
    int queue[MAX], front = 0, rear = 0;
    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    printf("BFS traversal starting from vertex %d: ", startVertex);
    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);
        for (int i = 0; i < vertices; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
            	queue[rear++] = i;
            	visited[i] = 1;
            }
        }
	}
    printf("\n");
}
void dfs(int vertex, int vertices) {
    visited[vertex] = 1;
    printf("%d ", vertex);
 
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfs(i, vertices);
        }
	} }
void resetVisited(int vertices) {
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
	} }
int main() {
    int vertices, edges, startVertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }  }
    printf("Enter the edges (u v) where u and v are vertices with 0-based indexing:\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
	}
    printf("Enter the starting vertex for BFS and DFS: ");
    scanf("%d", &startVertex);
    resetVisited(vertices);
    bfs(startVertex, vertices);
    resetVisited(vertices);
    printf("DFS traversal starting from vertex %d: ", startVertex);
    dfs(startVertex, vertices);
    printf("\n");
    return 0;
}
