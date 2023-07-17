/*
  ให้นักศึกษาเขียนโปรแกรมรับ Input เป็นตัวเลขฐาน 10 แล้วแสดงผลเป็นเลขฐาน 2

ตัวอย่าง
input : 22
output : 10110

input : 10
output : 1010
  */

#include <stdio.h>
#include <math.h>

int main () {
    int inputBase = 10, targetBase = 2;
    int input, target = 0, powerFactor = 0;

    scanf("%d", &input);

    while (input / (int)(pow(targetBase, powerFactor)) > 0) {
        powerFactor++;
    }

    for (int i = powerFactor; i >= 0; i--) {
        if (input / (int)(pow(targetBase, i)) > 0) {
            target += (input / (int)(pow(targetBase, i))) * (int)(pow(10, i));
            input -= (int)(pow(targetBase, i));
        }
    }

    printf("%d", target);
}