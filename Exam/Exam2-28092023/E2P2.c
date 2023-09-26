#include <stdio.h>

int main () {
    int size;
    scanf("%d", &size);

    for (int i = 1; i <= size; i++) {
        // top and bottom
        if (i == 1 || i == size) {
            for (int j = 1; j <= size; j++) {
                printf("*");
            }
        }
        else {
            int symbolPos1 = i;
            int symbolPos2 = size - i + 1;
            for (int j = 1; j <= size; j++) {
                if (j == 1 || j == size) {
                    printf("*");
                }
                else if (j == symbolPos1 || j == symbolPos2) {
                    printf("*");
                }
                else {
                    printf(" ");
                }
            }
        }

        printf("\n");
    }
}