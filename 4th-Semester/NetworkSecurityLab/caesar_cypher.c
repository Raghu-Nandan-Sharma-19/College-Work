#include <stdio.h>
#include <time.h>
#include <string.h>

void encryption(char str[], int shift) {
    clock_t t;
    t = clock(); 
    
    char ans[256];
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        ans[i] = ch;
    }
    
    ans[len] = '\0';
    printf("Encrypted: %s\n", ans);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Encryption took %.2f seconds to execute \n", time_taken);
}

void decryption(char str[], int shift) {
    clock_t t;
    t = clock();

    char ans[256];
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - shift + 26) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        ans[i] = ch;
    }
    ans[len] = '\0';
    printf("Decrypted: %s\n", ans);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Decryption took %.2f seconds to execute \n", time_taken);
}

int main() {
    char str[100];
    int shift = 5;

    printf("Enter a string to encrypt: ");
    scanf("%s", str); 
    
    
    encryption(str, shift);
    

    printf("Enter a string to decrypt: ");
    scanf("%s", str);

    decryption(str, shift);
    
    return 0;
}
