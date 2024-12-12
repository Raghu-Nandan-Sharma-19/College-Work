#include <stdio.h>
#include <string.h>
#include <time.h>

void extractSubstring(char str[], int start, int length, char result[]) {
    int i;
    for (i = 0; i < length && str[start + i] != '\0'; i++) {
        result[i] = str[start + i];
    }
    result[i] = '\0';
}

int main() {
    char str[1000], substring[1000];
    int start, length;

    printf("Enter the string: ");
    scanf("%[^\n]s", str);

    printf("Enter starting index and length of substring: ");
    scanf("%d %d", &start, &length);

    extractSubstring(str, start, length, substring);

    printf("Extracted substring: %s\n", substring);
    printf("Length of the string: %lu\n", strlen(str));

    return 0;
}

