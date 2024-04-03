// Program to demonstrate three dimensional array
#include<stdio.h>
int main() {
    int i, j, k, size, rows, columns, arr[100][100][100];
    printf("Enter number of matrix : ");
    scanf("%d", &size);
    printf("Enter number of rows : ");
    scanf("%d", &rows);
    printf("Enter number of columns : ");
    scanf("%d", &columns);
    for(i=0; i<size; i++) {
        for(j=0; j<rows; j++) {
            for(k=0; k<columns; k++) {
                scanf("%d ", &arr[i][j][k]);
            }
        }
    }
    for(i=0; i<size; i++) {
        for(j=0; j<rows; j++) {
            for(k=0; k<columns; k++) {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}