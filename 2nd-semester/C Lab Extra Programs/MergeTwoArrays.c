#include<stdio.h>
void mergeArrays(int arr1[], int arr2[], int n1, int n2) {
    if(n1==n2) {
        int arr3[1000];
        for(int i=0; i<n1; i++) {
            arr3[i]=arr1[i];
        }
        for(int i=0; i<n2; i++) {
            arr3[n1+i]=arr2[i];
        }
        printf("Merged array is : \n");
        for(int i=0; i<n1+n2; i++) {
            printf("%d ", arr3[i]);
        }
        printf("\n");
        printf("Array in descending oder is : \n");
        for(int i=0; i<n1+n2; i++) {
            for(int j=i+1; j<n1+n2; j++) {
                if(arr3[i]<arr3[j]) {
                    int temp=arr3[i];
                    arr3[i]=arr3[j];
                    arr3[j]=temp;
                }
            }
        }
        for(int i=0; i<n1+n2; i++) {
            printf("%d ", arr3[i]);
        }
    } else {
        printf("Both arrays are not of same size. cannot merge");
    }
}
int main() {
    int arr1[1000], arr2[1000], size1, size2;
    printf("Enter the size of first array : ");
    scanf("%d", &size1);
    printf("Enter elements of first array : \n");
    for(int i=0; i<size1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the size of second array :\n");
    scanf("%d", &size2);
    printf("Enter elements of second array : \n");
    for(int i=0; i<size2; i++) {
        scanf("%d", &arr2[i]);
    }
    printf("First array is : \n");
    for(int i=0; i<size1; i++) {
        printf("%d ", arr1[i]);
    }printf("\n");
    printf("Second array is : \n");
    for(int i=0; i<size2; i++) {
        printf("%d ", arr2[i]);
    }printf("\n");
    mergeArrays(arr1, arr2, size1, size2);
    return 0;
}