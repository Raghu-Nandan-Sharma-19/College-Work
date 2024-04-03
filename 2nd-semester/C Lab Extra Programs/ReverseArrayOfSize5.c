// Write a program to reverse an array elements of size 5
#include<stdio.h>
void display(int arr[], int n) {
    printf("Array before reversing is :\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }printf("\n");
}
void reverseArray(int arr[], int n) {
    int start=0, end=n-1;
    while(start<end) {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
int main() {
    int n=5;
    int arr[n];
    printf("Enter %d elements :\n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    display(arr, n);
    printf("The array after reversing is :\n");
    reverseArray(arr, n);
    display(arr, n);
    return 0;
}