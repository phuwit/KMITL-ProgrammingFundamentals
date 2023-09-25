// Multiplication table

#include <stdio.h>

int main () {
    int tableNum;
    scanf("%d", &tableNum);


    for (int i = 1; i <= 12; i++) {
        printf("%d x %d = %d\n", tableNum, i, tableNum * i);
    }
}