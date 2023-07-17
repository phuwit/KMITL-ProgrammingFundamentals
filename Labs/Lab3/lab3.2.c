#include<stdio.h>

int main() {
    int n = 10000;
    int i = 1;

    while (i <= n) {
        int j = 1;
        int sum = 0;
        while (j < i) {
            if (i % j == 0){
                sum += j;
            }
            j++;
        }

        if (sum == i) {
            printf("%d\n", i);
        }
        i++;
    }  
}

