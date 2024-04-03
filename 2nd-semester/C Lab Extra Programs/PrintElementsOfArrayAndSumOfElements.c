// Print Elements Of Array And Sum Of Element
#include<stdio.h>
int main(){
    int n, arr[100], sum=0;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    printf("Enter %d elements : \n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Printing array : \n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
        sum += arr[i];
    }
    printf("\n");
    printf("Sum of elements of array is %d\n", sum);
    return 0;
}