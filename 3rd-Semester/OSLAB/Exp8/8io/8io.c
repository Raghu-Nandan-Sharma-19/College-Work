#include<stdio.h>
#include<unistd.h>
int main() {
        FILE *file = fopen("output.txt", "w");
        if(!file) {
                perror("Unable to open file");
                return 1;
        }
        for(int i = 0; ; i++) {
                fprintf(file, "Writing line %d to the file\n", i);
                fflush(file);
                usleep(1000);
        }
        fclose(file);
        return 0;
}
