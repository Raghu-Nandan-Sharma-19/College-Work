#include <stdio.h>
#include <string.h>
#include <ctype.h>

void compressString(const char* str) {
    int len = strlen(str);
    int count = 1;

    for (int i = 0; i < len; i++) {
        char current = tolower(str[i]);
        char next = tolower(str[i + 1]);

        if (current == next) {
            count++;
        } else {
            printf("%d%c", count, current);
            count = 1;
        }
    }
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    scanf("%s", str);
    compressString(str);
    return 0;
}