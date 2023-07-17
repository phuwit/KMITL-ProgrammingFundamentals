/*
  จงเขียนโปรแกรมรับ input เป็นตัวเลข 10 ตัว แล้วทำการสร้างฟังก์ชั่น bubble_sort() ในการเรียงลำดับตัวเลขจากน้อย ไปมาก โดยใช้ bubble sort algorithm 

Test Case 1:
Input Numbers: 5, 2, 9, 1, 7, 4, 6, 3, 8, 10
Expected Output: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

Test Case 2:
Input Numbers: 1, 3, 5, 7, 9, 2, 4, 6, 8, 10
Expected Output: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
*/

#include <stdio.h>

int *bubble_sort(int toSort[], int size);
int is_sorted(int array[], int size);

int main(void) {
    int inputSize = 10;
    int input[inputSize];

    for (int i = 0; i < inputSize; i++) {
        scanf("%d,", &input[i]);
    }

    int *sorted = bubble_sort(input, inputSize);

    for (int i = 0; i < inputSize; i++) {
        printf("%d", *(sorted + i));
        if (i != inputSize - 1) {
            printf(", ");
        }
    }
}

int *bubble_sort(int toSort[], int size) {
    // int sorted[size];

    while (is_sorted(toSort, size) == 1) {
        for (int i = 1; i < size; i++) {
            if (toSort[i] < toSort[i - 1]) {
                int hold = toSort[i - 1];
                toSort[i - 1] = toSort[i];
                toSort[i] = hold;
            }
        }  
    }

    return toSort;
}

int is_sorted(int array[], int size) {
    for (int i = 1; i < size; i++) {
        if (array[i] < array[i - 1]) {
            return 1;
        }
    }
    return 0;
}