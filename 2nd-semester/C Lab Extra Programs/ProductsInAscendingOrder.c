// A salesperson is trying to arrange the products according to their prices(in ascending order) 
// Help him out by writing the logic in superMarket(int a, int n)

#include<stdio.h>
void displayPrices(int a[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
}
void superMarket(int a[], int n) {
    // for(int i=n-1; i>=1; i--) {
    //     for(int j=0; j<=i-1; j++) {
    //         if(a[j]>a[j+1]) {
    //             int temp=a[j];
    //             a[j]=a[j+1];
    //             a[j+1]=temp;
    //         }
    //     }
    // }
    int c, d, t, i;
    for(c=0; c<n-1; c++) {
        for(d=0; d<n-c-1; d++) {
            if(a[d]>a[d+1]) {
                t=a[d];
                a[d]=a[d+1];
                a[d+1]=t;
            }
        }
    }
}
int main() {
    int n, arr[1000];
    printf("Enter the number of products :\n");
    scanf("%d", &n);
    printf("Enter the prices of %d products :\n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Prices of products in ascending order is :\n");
    superMarket(arr, n);
    displayPrices(arr, n);
    return 0;
}