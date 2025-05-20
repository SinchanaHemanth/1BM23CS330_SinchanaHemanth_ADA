#include <stdio.h>

#define MAX 10
#define INF 999

int parent[MAX];

// Find the root of the set
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union of two sets
void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int n, cost[MAX][MAX];
    int i, j, u, v, min, edges = 0, minCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (999 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initialize parent array
    for (i = 0; i < n; i++) {
        parent[i] = i;
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");
    while (edges < n - 1) {
        min = INF;

        // Find the smallest edge
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min && find(i) != find(j)) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        unionSet(u, v);
        printf("Edge %d: (%d - %d) cost = %d\n", edges + 1, u, v, min);
        minCost += min;
        edges++;
        cost[u][v] = cost[v][u] = INF;  // Mark as used
    }

    printf("\nTotal cost of MST = %d\n", minCost);

    return 0;
}
