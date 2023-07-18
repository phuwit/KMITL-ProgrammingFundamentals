/*
  ให้นักศึกษาเขียนโปรแกรมรับ Input เป็นหมายเลขบัตรประจำตัวประชาชน 13 หลัก แล้วโปรแกรมแสดงผลการตรวจสอบว่าเป็นหมายเลขบัตรประชาชน 13 หลักที่มีรูปแบบถูกต้องหรือไม่

ตัวอย่าง
input : 1234567890121
output : PersonalID

input : 9876543210981
output : Not PersonalID
*/

#include <stdio.h>

int main(void) {
    char id[13];
    int checkDigit = 0;
    scanf("%s", id);

    for (int i = 0; i <= 11; i++) {
        checkDigit += (13 - i) * ((int)id[i] - 48);
    }

    checkDigit = checkDigit % 11;
    if (checkDigit <= 1) {
        checkDigit = 1 - checkDigit;
    }
    else {
        checkDigit = 11 - checkDigit;
    }


    if (checkDigit ==  (int)id[12] - 48) {
        printf("PersonalID");
    }
    else {
        printf("Not PersonalID");
    }
}