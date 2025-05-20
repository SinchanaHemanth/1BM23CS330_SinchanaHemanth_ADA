#include<stdio.h>
#include<time.h>
int partition(int arr[],int low, int high) {
    int pivot = arr[low];
    int start = low;
    int end = high;
    while(start<=end) {
        while(arr[start]<=pivot) {
            start++;
        }
        while(arr[end]>pivot) {
            end--;
        }
        if(start<end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[end];
    arr[end] = temp;
    return end;
}
void quicksort(int arr[],int low, int high) {
    if(low<high) {
        int pivotIndex = partition(arr,low,high);
        quicksort(arr,low,pivotIndex-1);
        quicksort(arr,pivotIndex+1,high);
    }
}
int main() {
    int n, arr[10];
    printf("Enter number of array elements\n");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    clock_t start, end;
    double time_taken;
    start = clock();
    quicksort(arr,0,n-1);
    end = clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Sorted elements\n");
    for(int i=0;i<n;i++) {
        printf("%d\t",arr[i]);
    }
    printf("Time taken = %f\n",time_taken);
}
