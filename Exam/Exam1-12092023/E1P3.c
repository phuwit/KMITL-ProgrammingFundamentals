// display the sum of 2 "middle" number

#include <stdio.h>
#include <math.h>

int main () {
    int inputNum[4];
    for (int i = 0; i < 4; i++) {
        scanf(" %d", &inputNum[i]);
    }

    // get max min int
    int max = inputNum[0];
    int min = inputNum[0];
    for (int i = 0; i < 4; i++) {
        if (max < inputNum[i]) {
            max = inputNum[i];
        }
        if (min > inputNum[i]) {
            min = inputNum[i];
        }
    }

    // summing not max and not min
    int sumMiddleInt = 0;
    for (int i = 0; i < 4; i++) {
        if (max != inputNum[i] && min != inputNum[i]) {
            sumMiddleInt += inputNum[i];
        }
    }

    printf("%d", sumMiddleInt);
}
