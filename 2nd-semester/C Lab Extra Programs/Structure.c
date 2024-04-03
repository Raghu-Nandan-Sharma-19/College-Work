#include<stdio.h>
struct student {
    char name[50];
    int roll;
    float percentage;
};
int main() {
    int n;
    printf("Enter the number of students : \n");
    scanf("%d", &n);
    struct student s[n];
    for(int i=0; i<n; i++) {
        printf("Enter the details of student %d :\n",i+1);
        printf("Name : ");
        scanf("%s", &s[i].name);
        printf("Roll Number : ");
        scanf("%d", &s[i].roll);
        printf("Percentage : ");
        scanf("%f", &s[i].percentage);
    }
    for(int i=0; i<n; i++) {
        printf("Percentage of %s (Roll Number : %d) is : %.2f\n", s[i].name, s[i].roll, s[i].percentage);
    }
    return 0;
}