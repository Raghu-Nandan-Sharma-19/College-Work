// input array of n elements double size of array and make all elements zero except last element
// 0 0 0 0 0 0 0 0 0 5
#include<stdio.h>
void disply(int a[], int n) { // display function
    for(int i=0; i<n; i++) { // loop to display the array
        printf("%d ", a[i]); 
    }
}
void doubleSize(int a[], int n) {
    for(int i=n; i<2*n; i++) {
        a[i]=0;
    }
    a[2*n-1]=a[n-1];
    for(int i=0; i<n; i++) {
        a[i]=0;
    }
}
int main() {
    int n, arr[1000];
    printf("Enter the number of elements :\n");
    scanf("%d", &n);
    printf("Enter %d elements :\n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]); 
    }
    doubleSize(arr, n);
    printf("Array after doubling the size and making all elements zero except last element is :\n");
    disply(arr, 2*n);
    return 0;
}