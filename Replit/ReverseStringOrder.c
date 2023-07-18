/*
  เขียนโปรแกรมรับ input เป็น string 1 ตัวที่ประกอบด้วยคำหลายๆ คำ คั่นด้วยช่องว่าง แล้วแสดงผลลัพธ์เป็น string ที่มีการสลับลำดับคำจากหลังมาหน้า

input : abc def ghi jkl
outupt : jkl ghi def abc
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    const int MAX_INPUT_SIZE = 100;
    char input[MAX_INPUT_SIZE];
    int spaceIndex[MAX_INPUT_SIZE];

    fgets(input, MAX_INPUT_SIZE, stdin); 

    int realInputSize = strlen(input) - 1;
    int currentSpaceCount = 0;

    for (int i = realInputSize - 1; i >= 0; i--) {
        if (input[i] == ' ') {
            spaceIndex[currentSpaceCount] = i;
            currentSpaceCount++;
        }
    }

    // include first blob
    spaceIndex[currentSpaceCount] = -1;
    currentSpaceCount++;

    for (int i = 0; i < currentSpaceCount; i++) {
        for (int j = spaceIndex[i] + 1; j < realInputSize; j++) {
            if (input[j] == ' ' || input[j] == '\n') {
                break;
            }
            else {
                printf("%c", input[j]);
            }
        }
        printf(" ");
    }
    // printf("%s", input);
}
