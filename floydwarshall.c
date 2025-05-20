//floyd-warshall algorithm
#include<stdio.h>
int cost[10][10], dist[10][10], n;
int min(int a, int b) {
    return (a<b)?a:b;
}
void floyd(int a[][10], int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            dist[i][j] = cost[i][j];
        }
    }
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
}
int main() {
    printf("Enter total number of vertices\n");
    scanf("%d",&n);
    printf("Enter cost adjacency matrix\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&cost[i][j]);
        }
    }
    floyd(cost,n);
    printf("Distance matrix\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%d\t",dist[i][j]);
        }
        printf("\n");
    }
}
