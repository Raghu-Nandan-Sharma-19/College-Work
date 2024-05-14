#include<stdio.h>

// Function to display the elements of an array
void display(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform selection sort on an array
void selectionSort(int arr[], int n) {
    // Iterate through the array
    for(int i=0; i<n-1; i++) {
        // Assume the current index as the index of the minimum element
        int mini = i;
        // Find the index of the minimum element in the unsorted portion of the array
        for(int j=i; j<n; j++) {
            if(arr[j] < arr[mini]) {
                mini = j;
            }
        }
        // Swap the minimum element with the first element of the unsorted portion
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp; 
    }
}

int main() {
    int n;
    // Input the size of the array
    scanf("%d", &n);
    // Declare an array of given size
    int arr[n];
    // Input elements into the array
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    // Display the array before sorting
    printf("Before selection sort : \n");
    display(arr, n);
    // Sort the array using selection sort algorithm
    printf("After selection sort : \n");
    selectionSort(arr, n);
    // Display the array after sorting
    display(arr, n);
    return 0;
}
