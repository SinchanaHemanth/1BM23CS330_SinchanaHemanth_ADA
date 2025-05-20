//warshall algorithm
#include<stdio.h>
int a[10][10], p[10][10];
void warshall(int a[][10], int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            p[i][j] = a[i][j];
        }
    }
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(p[i][j]==1 || p[i][k]==1 && p[k][j]==1) {
                    p[i][j]=1;
                }
            }
        }
    }
}
int main() {
    int n;
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    warshall(a,n);
    printf("Path matrix\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%d\t",p[i][j]);
        }
        printf("\n");
    }
}
