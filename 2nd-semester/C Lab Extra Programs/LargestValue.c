#include<stdio.h>
int findLargestElement(int arr[], int size) {
    int largestElement=arr[0];
    for(int i=0; i<size; i++) {
        if(arr[i]>arr[largestElement]) {
            largestElement=i;
        }
    }
    printf("Largest element is found at %d index", largestElement);
}
int main() {
    int arr[1000], size;
    printf("Enter the size of array :\n");
    scanf("%d", &size);
    printf("Enter %d elements :\n", size);
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The array is :\n");
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    findLargestElement(arr, size);
    return 0;
}