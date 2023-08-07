/*
  จากลำดับตัวเลข Fibonacci ตัวอย่าง :

Fibonacci Sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181

จงเขียนโปรแกรมรับตัวเลข 1 ตัว แล้วแสดงตัวเลข Fibonacci ในลำดับดังกล่าวเช่น

input : 4
output : 2

input : 10
output : 34*/

#include <stdio.h>

int getFibonacciNumFromIndex (int);

int main(void) {
    int n;
    scanf("%d", &n);

    n--;

    int fibonacciNum = getFibonacciNumFromIndex(n);

    printf("%d", fibonacciNum);
}

int getFibonacciNumFromIndex (int index) {
    if (index == -1) {
        return 0;
    }

    int currentNum = 1;
    int lastNum = 1;

    for (int i = 2; i < index; i++) {
        int hold = currentNum;
        currentNum += lastNum;
        lastNum = hold;
    }

    return currentNum;
}