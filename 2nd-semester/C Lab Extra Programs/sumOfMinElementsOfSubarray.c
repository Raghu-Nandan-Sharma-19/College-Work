#include<stdio.h>

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int min = arr[i];
        for (int j = i; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
            }
            sum += min;
        }
    }

    printf("Sum of the minimum elements of all contiguous subarrays: %d\n", sum);

    return 0;
}
