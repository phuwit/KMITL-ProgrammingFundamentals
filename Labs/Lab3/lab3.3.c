#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    char image[n*2][n*2];
    for (int i = 1; i < n * 2; i++) {
        for (int j = 1; j < n * 2; j++) {
            image[i][j] = '*';
        }
    }

    int countUp, countDown;
    countUp = 2;
    countDown = (n * 2) - 2;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = countUp; j <= countDown; j++) {
            image[i][j] = ' ';
            image[2 * n - i][j] = ' ';
        }
        countUp++;
        countDown--;
    }

    for (int i = 1; i < n * 2; i++) {
        for (int j = 1; j < n * 2; j++) {
            printf("%c", image[i][j]);
        }
        printf("\n");
    }
}

