/*
  ให้นักศึกษาเขียนโปรแกรมรับ input เป็น string จำนวน 2 ชุด (long_string, sub_string) แล้วทำการค้นหาว่ามี sub_string อยู่ที่ตำแหน่ง (index) ใดใน long_string ถ้าไม่พบ ให้แสดงตำแหน่งเป็น -1

Test Case 1:
String: "Hello World"
Substring: "Hello"
Expected Output: Substring found at index 0

Test Case 2:
String: "OpenAI is amazing"
Substring: "is"
Expected Output: Substring found at index 7
  */

#include <stdio.h>
#include <string.h>

int main(void) {
    int inputMaxSize = 100, longRealSize, subRealSize;
    char long_string[inputMaxSize], sub_string[inputMaxSize];
    fgets(long_string, inputMaxSize, stdin);
    fgets(sub_string, inputMaxSize, stdin);

    longRealSize = strlen(long_string) - 1;
    subRealSize = strlen(sub_string) - 1;

    int foundIndex = -1;
    for (int i = 0; i < longRealSize; i++) {
        int isFound = 0;
        for (int j = 0; j < subRealSize; j++){
            char DebugViewlong_stringij = long_string[i + j];
            char DebugViewsub_stringj = sub_string[j];
            if(long_string[i + j] != sub_string[j]) {
                isFound = 1;
                break;
            }
        }

        if (isFound == 0) {
            foundIndex = i;
            break;
        }
    }

    printf("%d", foundIndex);
}