#include <stdio.h>

int main () {
    int length, whitespace, i, j, k;
    printf("Enter number : ");
    scanf("%d", &length);
    whitespace = length - 2;

    i = 0;
    while (i <= length - 1) {
        j = 0;
        if (i == 0 || i == length - 1) {
            while (j < length)
            {
                printf("*");
                j++;
            }
            printf("\n");
        }
        else {
            printf("*");
            k = 0;
            while (k < whitespace) {
                printf(" ");
                k++;
            }
            printf("*\n");
        }
    i++;
    }
}