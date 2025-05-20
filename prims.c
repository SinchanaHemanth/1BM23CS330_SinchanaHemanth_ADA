#include<stdio.h>
int main() {
    int cost[10][10], visited[10];
    int u,v,n,min,minCost=0,edges=0;
    printf("Enter number of edges\n");
    scanf("%d",&n);
    printf("Enter cost adjacency matrix\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&cost[i][j]);
        }
    }
    for(int i=0;i<n;i++) {
        visited[i]=0;
    }
    visited[0]=1;
    while(edges<n-1) {
        min = 999,u=-1,v=-1;
        for(int i=0;i<n;i++) {
            if(visited[i]==1) {
                for(int j=0;j<n;j++) {
                    if(visited[j]==0 && cost[i][j]<min) {
                        min=cost[i][j];
                        u=i;v=j;
                    }
                }
            }
        }
        if(u!=-1 && v!=-1) {
            printf("Edge %d (%d - %d) Cost = %d\n",edges+1,u,v,min);
            visited[v]=1;
            minCost+=min;
            edges++;
        }
    }
    printf("Minimum cost = %d\n",minCost);
}
