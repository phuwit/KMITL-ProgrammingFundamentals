/*
  ให้นักศึกษาเขียนโปรแกรมรับจำนวนเต็ม 5 จำนวน เก็บใน array แล้วตรวจว่าลำดับตัวเลขที่รับมามีการเรียงจากน้อยไปมากหรือไม่

input : 2 4 5 6 7
output : Ascending order

input : 2 8 5 3 7
output : Not ascending order
*/

#include <stdio.h>

int main(void) {
    const int ARRAY_LENGTH = 5;
    int n[ARRAY_LENGTH], isSorted = 1;
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        scanf("%d ", &n[i]);
    }

    for (int i = 0; i < ARRAY_LENGTH - 1; i++) {
        if (n[i] > n[i + 1]) {
            isSorted = 0;
            break;
        }
    }

    if (isSorted == 1) {
        printf("Ascending order");
    }
    else {
        printf("Not ascending order");
    }
}