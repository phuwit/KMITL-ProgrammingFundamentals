#include <stdio.h>

int main () {
    int n, i;
    printf("Enter number : ");
    scanf("%d", &n);

    printf("Factoring result : ");
    i = 2;
    while (i <= n) {
        if (n % i == 0) {
            n = n / i;
            printf("%d", i);
            
            if (n != 1) {
                printf(" x "); 
            }
            else {
                break;
            }
        }
        
        else {
            i++;
        }
    }
}