/*
  เขียนโปรแกรมรับ input เป็นตัวเลข 1 ตัวแล้วแสดงผล ตัวประกอบที่มีค่ามากที่สุด (maximum prime factor)

input : 21
output : 7

input : 1110
output : 37
  */

#include <stdio.h>

int isPrime(int n) {
    int isPrime = 0;
    for (int i = 2; i < n; i++) {
        if(n % i == 0) {
            isPrime = 1;
            break;
        }
    }
    return isPrime;
}

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = n - 1; i >= 2; i--) {
        if (n % i == 0) {
            if (isPrime(i) == 0) {
                printf("%d", i);
                break;
            }
        }
    }
}