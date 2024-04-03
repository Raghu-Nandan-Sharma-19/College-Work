// Even or odd using functions
#include <stdio.h>
#include <stdbool.h>
bool evenOrOdd(int num) {
    if(num%2==0) {
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int a;
    printf("Enter any number : ");
    scanf("%d", &a);
    if(evenOrOdd(a)) {
        printf("Even number.");
    } else {
        printf("Odd number.");
    }
    return 0;
}