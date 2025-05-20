#include<stdio.h>
int max(int a, int b) {
    return (a>b)?a:b;
}
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++) {
        for(int w=0;w<=W;w++) {
            if(w==0||i==0) {
                dp[i][w]=0;
            }
            else if(wt[i-1]>w) {
                dp[i][w] = dp[i-1][w];
            }
            else {
                dp[i][w] = max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
            }
        }
    }
    return dp[n][W];
}
int main() {
    int W,wt[100],val[100],n;
    printf("Enter total number of items\n");
    scanf("%d",&n);
    printf("Enter total capacity\n");
    scanf("%d",&W);
    printf("Enter weight of each item\n");
    for(int i=0;i<n;i++) {
        scanf("%d",&wt[i]);
    }
    printf("Enter value of each item\n");
    for(int i=0;i<n;i++) {
        scanf("%d",&val[i]);
    }
    int maxVal = knapsack(W,wt,val,n);
    printf("Maximum value = %d\n",maxVal);
}
