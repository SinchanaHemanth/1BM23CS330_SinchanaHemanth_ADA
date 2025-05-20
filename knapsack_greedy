#include<stdio.h>
int main() {
    int n = 4;
    int wt[4] = {5,10,15,20}, val[4]={100,200,150,50}, used[4], capacity = 32;
    int remainingCapacity = capacity;
    float totalValue = 0.0;
    for(int i=0;i<n;i++) {
        used[i]=0;
    }
    while(remainingCapacity>0) {
        int bestIndex = -1;
        float bestRatio = 0.0;
        for(int i=0;i<n;i++) {
            if(used[i]==0) {
                float ratio = (float)val[i]/wt[i];
                if(bestIndex==-1 || ratio>bestRatio) {
                    bestIndex=i;
                    bestRatio=ratio;
                }
            }
        }
        if(bestIndex==-1) {
            break;
        }
        used[bestIndex]=1;
        if(wt[bestIndex]<=remainingCapacity) {
            remainingCapacity-=wt[bestIndex];
            totalValue += val[bestIndex];
            printf("Added entire item %d (weight = %d, value = %d)\n",bestIndex+1,wt[bestIndex],val[bestIndex]);
        }
        else {
            float fraction = (float)remainingCapacity/wt[bestIndex];
            totalValue += fraction*val[bestIndex];
            remainingCapacity = 0;
            printf("Added %.2f of item %d (weight = %d, value = %d)\n",fraction*100,bestIndex+1,wt[bestIndex],val[bestIndex]);
        }
    }
    printf("Total value in knapsack = %.2f\n",totalValue);
}
