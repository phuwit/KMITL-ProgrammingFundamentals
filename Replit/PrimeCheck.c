/*

  ให้นักศึกษาเขียนโปรแกรมรับ Input เป็นตัวเลข 1
ตัวแล้วตรวจสอบว่าตัวเลขที่ได้รับมาเป็นตัวเลขจำนวนเฉพาะหรือไม่

ตัวอย่าง
input : 13
output : Prime number

input : 56
output : Not prime number
*/

#include <stdio.h>

int isPrime (int);

int main(void) {
  int n;
  scanf("%d", &n);

  int nPrimeStatus; 
  nPrimeStatus = isPrime(n);

  if (nPrimeStatus == 1) {
    printf("Prime number");
  } else {
    printf("Not prime number");
  }
}

int isPrime (int input) {
    int isPrime = 1;
    for (int i = 2; i < input; i++) {
        if (input % i == 0) {
            isPrime = 0;
            break;
        }
    }
    return isPrime;
}