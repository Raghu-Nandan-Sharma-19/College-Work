#include <stdio.h>
#include <stdlib.h>
int main() {
    int *ptr, *p, i;
    ptr=(int*)malloc(4*sizeof(int));
    p=ptr;
    if(ptr==NULL) {
        printf("Memory is full.\n");
    } else {
        printf("Enter the 4 elements :\n");
        for(i=0; i<4; i++) {
            scanf("%d", ptr);
            ptr++;  
        }
    }
    printf("The elements are : \n");
    for(i=0; i<4; i++) {
        printf("%d\n", *p);
        p++;
    }
    return 0;
}