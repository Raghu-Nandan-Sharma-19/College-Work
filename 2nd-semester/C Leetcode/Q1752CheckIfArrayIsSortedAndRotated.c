// Question: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
#include <stdio.h>
#include <stdbool.h>
bool check(int nums[]) {
    int count = 0;
    for(int i=0;i<sizeof(nums);i++) {
        if(nums[i] > nums[(i+1)%sizeof(nums)]) {
            count++;
        }
    }
    if(count > 1)
    return false;
    else
    return true;
}
int main() {
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter the elements of the array : ");
    for(int i=0;i<n;i++) {
        scanf("%d", &nums[i]);
    }
    if(check(nums))
    printf("True\n");
    else
    printf("False\n");
    return 0;
}