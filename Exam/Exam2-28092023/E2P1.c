#include <stdio.h>

int main () {
    int MAX_NUM = 10;
    int n[MAX_NUM], odd[MAX_NUM], even[MAX_NUM];
    int oddIndex = 0, evenIndex = 0;

    for (int i = 0; i < MAX_NUM; i++) {
        scanf("%d", &n[i]);

        if (n[i] == 0) {
            break;
        }
        else {
            if (n[i] % 2 == 0) {
                even[evenIndex] = n[i];
                evenIndex++;
            }
            else {
                odd[oddIndex] = n[i];
                oddIndex++;
            }
        }
    }

    printf("\n Odd  :");
    for (int i = 0; i < oddIndex; i++) {
        printf(" %d", odd[i]);
    }

    printf("\n Even :");
    for (int i = 0; i < evenIndex; i++) {
        printf(" %d", even[i]);
    }
}