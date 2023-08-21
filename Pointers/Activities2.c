#include <stdio.h>
#include <string.h>

int main () {
    char inputString[100];
    scanf("%s", inputString);

    char* cursorIncrease = inputString;
    char* cursorDecrease = &inputString[strlen(inputString) - 1];

    char isPalindrome = 'T';
    
    while (cursorIncrease < cursorDecrease)
    {
        if (*cursorIncrease != *cursorDecrease) {
            isPalindrome = 'F';
            break;
        }

        cursorDecrease--;
        cursorIncrease++;
    }

    if (isPalindrome == 'T') {
        printf("Palindrome");
    }
    else {
        printf("Not Palindrome");
    }
}