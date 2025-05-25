#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX], stack[MAX], top = -1;

void dfs(int v, int n) {
    visited[v] = 1;
    for (int i = 0; i < n; i++)
        if (graph[v][i] && !visited[i])
            dfs(i, n);
    stack[++top] = v;
}

void topologicalSort(int n) {
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, n);

    printf("Topological Order: ");
    while (top >= 0)
        printf("%d ", stack[top--]);
    printf("\n");
}

int main() {
    int n, e, u, v;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }
    topologicalSort(n);
    return 0;
}
