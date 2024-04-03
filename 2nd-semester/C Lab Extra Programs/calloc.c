#include<stdio.h>
#include<stdlib.h>
int main() {
    int *ptr, *p, i,n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    ptr=(int*)calloc(n,sizeof(int));
    p=ptr;
    if(ptr==NULL) {
        printf("Memory is full.\n");
    } else {
        printf("Enter %d elements :\n", n);
        for(i=0; i<n; i++) {
            scanf("%d", ptr);
            ptr++;  
        }
    }
    printf("The elements are : \n");
    for(i=0; i<n; i++) {
        printf("%d\n", *p);
        p++;
    }
    return 0;
}