/*
  เขียนโปรแกรมรับ input เป็นตัวเลข 8 ตัวแล้วแสดงผลตัวเลขที่มีค่ามากที่สุดเป็นอันดับ 2

Test Case 1:
input : 10, 5, 8, 3, 12, 7, 15, 9
Expected Output: Second Largest Element = 12

Test Case 2:
input : 6, 3, 9, 1, 4, 5, 7, 2
Expected Output: Second Largest Element = 7
*/

#include <stdio.h>

int main(void) {
    int inputSize = 8;
    int input[inputSize];

    for (int i = 0; i < inputSize; i++) {
        scanf("%d,", &input[i]);
    }

    int max, secondmax;
    max = input[0];
    
    for (int i = 1; i < inputSize; i++) {
        if (input[i] > max){
            secondmax = max;
            max = input[i];
        }
        else if (input[i] > secondmax) {
            secondmax = input[i];
        }
    }

    printf("%d", secondmax);
}