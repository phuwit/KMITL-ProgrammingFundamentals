/*
  จงเขียนโปรแกรมเพื่อรับ input เป็นตัวเลข 10 ตัว แล้วแสดงผลว่า ตัวแลขที่ป้อนมีตัวเลขอะไรบ้าง และแต่ละเลขมีจำนวนกี่ตัว

Test Case 1:
input : 1, 2, 3, 4, 5, 1, 2, 3, 4, 5
Expected Output:
Element 1: Frequency = 2
Element 2: Frequency = 2
Element 3: Frequency = 2
Element 4: Frequency = 2
Element 5: Frequency = 2


Test Case 2:
input : 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
Expected Output:
Element 1: Frequency = 10
  */

#include <stdio.h>

int main(void) {
    int inputSize = 10, frequencySize = 21;
    int input[inputSize], frequency[frequencySize];

    for (int i = 0; i < inputSize; i++) {
        scanf("%d,", &input[i]);
    }

    for (int i = 0; i < frequencySize; i++) {
        frequency[i] = 0;
    }

    for (int i = 0; i < inputSize; i++) {
        int n = input[i];
        frequency[n]++;
    }

    for (int i = 0; i < frequencySize; i++) {
        if (frequency[i] != 0) {
            printf("Element %d: Frequency = %d\n", i, frequency[i]);
        }
    }
}