//mergesort algorithm
#include<stdio.h>
#include<time.h>
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int i,j,k;
    int L[n1],R[n2];
    for(i=0;i<n1;i++) {
        L[i]=arr[left+i];
    }
    for(j=0;j<n2;j++) {
        R[j]=arr[mid+1+j];
    }
    i=0,j=0,k=left;
    while(i<n1 && j<n2) {
        if(L[i]<R[j]) {
        arr[k++]=L[i++];
        }
        else {
            arr[k++]=R[j++];
        }

    }
    while(i<n1) {
        arr[k++]=L[i++];
    }
    while(j<n2) {
        arr[k++]=R[j++];
    }
}
void mergesort(int arr[], int left, int right) {
    if(left<right) {
        int mid = (left+right)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
int main() {
    int n, arr[10];
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter array to be sorted\n");
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    clock_t start, end;
    double time_taken;
    start = clock();
    mergesort(arr,0,n-1);
    end = clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Sorted array:\n");
    for(int i=0;i<n;i++) {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    printf("Time taken = %f\n",time_taken);
}
