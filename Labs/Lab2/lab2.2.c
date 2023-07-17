#include <stdio.h>

int main () {
    int n1, n2, max, i;
    printf("Enter first number : ");
    scanf("%d", &n1);
    printf("Enter second number : ");
    scanf("%d", &n2);

    if(n1 > n2) {
        max = n1;
    }
    else {
        max = n2;
    }

    i = max - 1;
    while(i >= 2) {
        if (n1 % i == 0 && n2 % i == 0) {
            printf("Greatest common divider = %d", i);
            break;
        }
        else {
            i = i - 1;
        }
    }
}