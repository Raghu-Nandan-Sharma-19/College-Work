#include<stdio.h>

// Function to display the elements of an array
void display(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]); // Printing each element of the array
    } 
    printf("\n"); // Moving to the next line after printing all elements
}

// Function to perform insertion sort on an array
void insertionSort(int arr[], int n) {
    for(int i=0; i<=n-1; i++) {
        int j = i;
        // Loop to shift elements to the right until correct position is found for arr[i]
        while(j>0 && arr[j-1]>arr[j]) {
            int temp = arr[j]; // Storing the current element in a temporary variable
            arr[j] = arr[j-1]; // Moving the element at arr[j-1] one position right
            arr[j-1] = temp;   // Placing the temporary variable value at arr[j-1]
            j--;               // Moving left to check previous elements for correct position
        }
    }
}

int main() {
    int n;
    scanf("%d", &n); // Taking input for the number of elements in the array
    int arr[n];      // Declaring an array of size n
    
    // Taking input for the elements of the array
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]); // Reading each element and storing it in the array
    }
    
    printf("Before insertion sort : \n");
    display(arr, n); // Displaying the array before sorting
    
    printf("After insertion sort : \n");
    insertionSort(arr, n); // Sorting the array using insertion sort
    display(arr, n);        // Displaying the sorted array
    
    return 0;
}