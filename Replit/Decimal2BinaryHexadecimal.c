/*
  
เขียนโปรแกรมรับ input เป็นตัวเลข 1 ตัวแล้วแสดงผลค่าตัวเลขฐานสอง และฐานสิบหกของตัวเลขนั้น

Input : 120
Output : 
1111000
78

Input : 534
Output:
1000010110
216

  */

#include <stdio.h>
#include <math.h>

void DecimalToBinary (int n, int powerFactor, char* result);
void DecimalToHexadecimal (int n, int powerFactor, char* result);
int GetDigitsDecimalToHexadecimal (int n);
int GetDigitsDecimalToBinary (int n);

int main () {
    int input;
    scanf("%d", &input);

    int hexDigits = GetDigitsDecimalToHexadecimal(input);
    char hexadecimal[hexDigits + 1];
    DecimalToHexadecimal(input, hexDigits, hexadecimal);

    int binDigits = GetDigitsDecimalToBinary(input);
    char binary[binDigits + 1];
    DecimalToBinary(input, binDigits, binary);

    printf("%s\n", binary);
    printf("%s", hexadecimal);
}

void DecimalToBinary (int n, int powerFactor, char* result) {
    const int inputBase = 10, targetBase = 2;
    int currentDigitInResult = 0;

    for (int i = powerFactor; i >= 0; i--) {
        int currentDigit = (n / (int)(pow(targetBase, i)));
        int currentDigitValue = currentDigit * (int)(pow(targetBase, i));
        n -= currentDigitValue;

        result[currentDigitInResult] = currentDigit + '0';
            currentDigitInResult++;
    }
    result[currentDigitInResult] = '\0';
}

void DecimalToHexadecimal (int n, int powerFactor, char* result) {
    const char digitSymbols[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    const int inputBase = 10, targetBase = 16;
    // char* result[powerFactor];
    int currentDigitInResult = 0;

    for (int i = powerFactor; i >= 0; i--) {
        int currentDigit = (n / (int)(pow(targetBase, i)));
        if (currentDigit > 0) {
            int currentDigitValue = currentDigit * (int)(pow(targetBase, i));
            n -= currentDigitValue;

            result[currentDigitInResult] = digitSymbols[currentDigit];
            currentDigitInResult++;
        }
    }
    result[currentDigitInResult] = '\0';
}

int GetDigitsDecimalToHexadecimal (int n) {
    const int inputBase = 10, targetBase = 16;
    int powerFactor = 0;
    while (n / (int)(pow(targetBase, powerFactor)) > 0) {
        powerFactor++;
    }

    return powerFactor;
}

int GetDigitsDecimalToBinary (int n) {
    const int inputBase = 10, targetBase = 2;
    int powerFactor = 0;
    while (n / (int)(pow(targetBase, powerFactor)) > 0) {
        powerFactor++;
    }

    return powerFactor;
}