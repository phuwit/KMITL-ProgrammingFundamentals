#include <stdio.h>

char convertToUpperCase (char lowerCase);

int main () {
    char inputString[100];
    char* cursor = inputString;
    scanf("%s", inputString);
    
    while (*cursor != '\0')
    {
        if (*cursor >= 'A' && *cursor <= 'Z') {
            printf("%c", *cursor);
        }
        else if (*cursor >= 'a' && *cursor <= 'z') {
            printf("%c", convertToUpperCase(*cursor));
        }

        cursor++;
    }
}

char convertToUpperCase (char lowerCase) {
    return lowerCase - 'a' +'A';
}