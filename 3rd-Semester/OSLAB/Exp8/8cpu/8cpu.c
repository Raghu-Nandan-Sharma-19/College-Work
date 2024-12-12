#include<stdio.h>
int main() {
        double result = 0;
        for(int i = 0; i < 10000000000; i++) {
                result += i * 1.5 / 3.7;
        }
	printf("Computation finished. Result %.1f\n", result);
        return 0;
}

