#include<stdio.h>
void display(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    } printf("\n");
}
void merge(int arr[], int low, int mid, int high) {
    int temp[1000];
    int left = low;
    int right = mid+1;
    int k = 0;
    while(left<=mid && right<=high) {
        if(arr[left]<=arr[right]) {
            temp[k++] = arr[left++];
        } else {
            temp[k++] = arr[right++];
        }
    }
    while(left<=mid) {
        temp[k++] = arr[left++];
    }
    while(right<=high) {
        temp[k++] = arr[right++];
    }
    for(int i=low; i<=high; i++) {
        arr[i] = temp[i-low];
    }
}
void mergeSort(int arr[], int low, int high) {
    if(low >= high) return;
    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Before merge sort : \n");
    display(arr, n);
    printf("After merge sort : \n");
    mergeSort(arr, 0, n-1);
    display(arr, n);
    return 0;
}