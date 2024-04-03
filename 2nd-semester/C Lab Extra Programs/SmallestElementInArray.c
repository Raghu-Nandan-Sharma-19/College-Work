#include<stdio.h>
void findSmallestElement(int arr[], int size) {
    int smallestElement=arr[0];
    for(int i=0; i<size; i++) {
        if(arr[i]<arr[smallestElement]) {
            smallestElement=i;
        }
    }
    printf("Smallest element is found at %d index", smallestElement);
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
    findSmallestElement(arr, size);
    printf("\n");
    return 0;
}