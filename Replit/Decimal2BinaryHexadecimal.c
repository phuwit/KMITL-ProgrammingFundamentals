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

int DecimalToBinary (int n);
char* DecimalToHexadecimal (int n, int powerFactor);
char GetDigitsDecimalToHexadecimal (int n);

int main () {
    int input;
    scanf("%d", &input);

    int hexDigits = GetDigitsDecimalToHexadecimal(input);
    char* hexadecimal = DecimalToHexadecimal(input, hexDigits);
}

int DecimalToBinary (int n) {
    const int inputBase = 10, targetBase = 2;
    int powerFactor;
    int result;
    while (n / (int)(pow(targetBase, powerFactor)) > 0) {
        powerFactor++;
    }

    for (int i = powerFactor; i >= 0; i--) {
        if (n / (int)(pow(targetBase, i)) > 0) {
            result += (n / (int)(pow(targetBase, i))) * (int)(pow(10, i));
            n -= (int)(pow(targetBase, i));
        }
    }

    return result;
}

char* DecimalToHexadecimal (int n, int powerFactor) {
    const char digitSymbols[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    const int inputBase = 10, targetBase = 16;
    char* result[powerFactor];
    int currentDigit = 0, currentDigitValue;

    for (int i = powerFactor; i >= 0; i--) {
        if (n / (int)(pow(targetBase, i)) > 0) {
            currentDigitValue = (n / (int)(pow(targetBase, i))) * (int)(pow(10, i));
            n -= (int)(pow(targetBase, i));

            result[currentDigit] = digitSymbols[currentDigitValue];
            currentDigit++;
        }
    }

    return result;
}

char GetDigitsDecimalToHexadecimal (int n) {
    const int inputBase = 10, targetBase = 16;
    int powerFactor;
    while (n / (int)(pow(targetBase, powerFactor)) > 0) {
        powerFactor++;
    }

    return powerFactor;
}