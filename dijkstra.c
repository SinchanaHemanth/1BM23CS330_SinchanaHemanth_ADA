#include<stdio.h>
#define MAX 20
int cost[MAX][MAX], distance[MAX], visited[MAX];
int main() {
    int n, source, u;
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    printf("Enter the cost adjacency matrix\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&cost[i][j]);
        }
    }
    printf("Enter source vertex\n");
    scanf("%d",&source);
    for(int i=0;i<n;i++) {
        distance[i] = cost[source][i];
        visited[i]=0;
    }
    visited[source]=1;
    distance[source]=0;
    for(int i=1;i<n;i++) {
        int min = 999;
        for(int j=0;j<n;j++) {
            if(visited[j]==0 && distance[j]<min) {
                min = distance[j];
                u = j;
            }
        }
        visited[u]=1;
        for(int j=0;j<n;j++) {
            if(visited[j]==0 && distance[u] + cost[u][j] < distance[j]) {
                distance[j] = distance[u] + cost[u][j];
            }
        }
    }
    printf("Shortest distance from source %d\n",source);
    for(int i=0;i<n;i++) {
        printf("%d --> %d = %d\n",source,i,distance[i]);
    }
}
