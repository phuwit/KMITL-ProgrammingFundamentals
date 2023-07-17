#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    while (n / 10 != 0)
    {
        int sum = 0;
        while (n / 10 != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        n = sum + n;
    }
    
    printf("%d", n);
}

