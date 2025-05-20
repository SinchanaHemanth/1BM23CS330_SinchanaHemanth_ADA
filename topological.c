//dfs 
#include<stdio.h>
int n, v[10], a[10][10], res[10], top=0;
void dfs(int i) {
    v[i]=1;
    for(int j=0;j<n;j++) {
        if(a[i][j]==1 && v[j]==0) {
            dfs(j);
        }
    }
    res[top++]=i;
}
void dfs_top() {
    for(int i=0;i<n;i++) {
        if(v[i]==0) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++) {
        v[i]=0;
    }
    dfs_top();
    printf("Topological order:\n");
    for(int i=top-1;i>=0;i--) {
        printf("%d\t",res[i]);
    }
}

//source removal 
#include<stdio.h>
int n, a[10][10], t[10], indegree[10], stack[10], top = -1;
void indegree_calc() {
    for(int i=0;i<n;i++) {
        int sum=0;
        for(int j=0;j<n;j++) {
            sum+=a[j][i];
        }
        indegree[i]=sum;
    }
}
void source_removal() {
    int v;
    for(int i=0;i<n;i++) {
        if(indegree[i]==0) {
            stack[++top]=i;
        }
    }
    int k=0;
    while(top!=-1) {
        v = stack[top--];
        t[k++]=v;
        for(int i=0;i<n;i++) {
            if(a[v][i]!=0) {
                indegree[i]--;
                if(indegree[i]==0) {
                    stack[++top]=i;
                }
            }
        }
    }
}
int main() {
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    indegree_calc();
    source_removal();
    printf("Topological order:\n");
    for(int i=0;i<n;i++) {
        printf("%d\t",t[i]);
    }
}
