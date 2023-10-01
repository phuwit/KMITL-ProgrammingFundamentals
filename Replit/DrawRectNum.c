/*
  เขียนโปรแกรมรับ input เป็นตัวเลข 2 ตัว ตัวแรก (m) คือตัวเลขสำหรับคำนวณความยาวด้านของรูปสี่เหลี่ยมจตุรัส โดยขนาดของรูปสี่เหลี่ยมจะมีด้านยาว =2m+1 ส่วนตัวที่สอง (n) คือตัวเลขที่อยู่ตรงกลาง โดยถ้า m=3,n=0 จะได้สี่เหลี่ยมที่มีความกว้าง = 7 และมีตัวเลขที่อยู่ตรงกลางคือ 0 ดังนี้

input :
m=3
n=0
output : 
3333333
3222223
3211123
3210123
3211123
3222223
3333333

input :
m = 2
n = 1
output :
33333
32223
32123
32223
33333


*/

#include <stdio.h>

int main () {
    int radius, width, centerNumber, edgeNumber;
    scanf("%d", &radius);
    scanf("%d", &centerNumber);

    width = (2 * radius) + 1;
    edgeNumber = radius + centerNumber;

    int rectangle[width][width];

    for (int heightCursor = 0; heightCursor < width; heightCursor++) {
        for (int widthCursor = 0; widthCursor < width; widthCursor++) {
            int distance;
            if (widthCursor + heightCursor >= 2 * radius) {
                int max = heightCursor;
                if (widthCursor > heightCursor) {
                    max = widthCursor;
                }

                if (max > radius) {
                    distance = max - radius + centerNumber;
                } else {
                    distance = radius - max + centerNumber;
                }
            } else {
                int min = heightCursor;
                if (widthCursor < heightCursor) {
                    min = widthCursor;
                }

                if (min > edgeNumber) {
                    distance = min - edgeNumber;
                } else {
                    distance = edgeNumber - min;
                }
            }

            rectangle[heightCursor][widthCursor] = (distance % 10);
        }
    }

    // for (int distance = 0; distance <= radius; distance++) {
    //     int rowsNegative = radius - distance;
    //     int rowsPositive = radius - distance;
    //     int columnNegative = radius - distance;
    //     int columnPositive = radius - distance;

    //     int n = distance + centerNumber;

    //     rectangle[columnNegative][rowsNegative] = n;
    //     rectangle[columnPositive][rowsNegative] = n;
    //     rectangle[columnNegative][rowsPositive] = n;
    //     rectangle[columnPositive][rowsPositive] = n;

    //     for (int widthCursor = 0; widthCursor < width; widthCursor++) {
    //         for (int heightCursor = 0; heightCursor < width; heightCursor++) {
    //         }
    //     }
    // }

    for (int widthCursor = 0; widthCursor < width; widthCursor++) {
        for (int heightCursor = 0; heightCursor < width; heightCursor++) {
            printf("%d", rectangle[heightCursor][widthCursor]);
        }
        printf("\n");
    }
}