#include <stdio.h>

void display(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void qs(int arr[], int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

void quickSort(int arr[], int size) {
    qs(arr, 0, size - 1);
}

int main() {
    int arr[100];
    int size;
    printf("Enter the size of the array : \n");
    scanf("%d", &size);
    printf("Enter %d elements : \n", size);
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Before Using quick Sort: \n");
    display(arr, size);
    quickSort(arr, size);
    printf("After Using quick sort: \n");
    display(arr, size);
    return 0;
}
