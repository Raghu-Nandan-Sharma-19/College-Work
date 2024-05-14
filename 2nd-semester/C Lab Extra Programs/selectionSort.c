#include<stdio.h>
void display(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    } printf("\n");
}
void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int mini = i;
        for(int j=i; j<n; j++) {
            if(arr[j] < arr[mini]) {
                mini = j;
            }
            
        }  
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp; 
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Before selection sort : \n");
    display(arr, n);
    printf("After selection sort : \n");
    selectionSort(arr, n);
    display(arr, n);
    return 0;
}