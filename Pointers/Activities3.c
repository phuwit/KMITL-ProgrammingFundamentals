#include <stdio.h>
#include <string.h>

int main () {
    char inputString1[100];
    printf(".\n");
    scanf("%s", inputString1);
    char inputString2[100];
    scanf("%s", inputString2);

    char* inputString1Ptr = inputString1;
    char* inputString2Ptr = inputString2;

    char isEqual = 'T';

    while (*inputString1Ptr != '\0' || *inputString2Ptr != '\0') {
        char currentCharString1;
        char currentCharString2;

        if (*inputString1Ptr != '\0') {
            // printf("%c", *inputString1Ptr);
            while (*(inputString1Ptr + 1) == *inputString1Ptr && *inputString1Ptr != '\0') {
                inputString1Ptr++;
            }
            currentCharString1 = *inputString1Ptr;
        }

        if (*inputString2Ptr != '\0') {
            // printf("%c", *inputString2Ptr);
            while (*(inputString2Ptr + 1) == *inputString2Ptr && *inputString2Ptr != '\0') {
                inputString2Ptr++;
            }
            currentCharString2 = *inputString2Ptr;
        }

        if (currentCharString1 != currentCharString2) {
            isEqual = 'F';
            break;
        }

        inputString1Ptr++;
        inputString2Ptr++;
    }

    if (isEqual == 'T') {
        printf("is equal");
    }
    else {
        printf("not equal");
    }
}