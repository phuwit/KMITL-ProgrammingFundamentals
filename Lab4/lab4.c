#include <stdio.h>

int is_number (char toCheck);
int check_glob (int from);

int main () {
    
}

int is_number (char toCheck) {
    if(toCheck >= 48 && toCheck <= 57) {
        // printf("%d is number\n", input[location] - 48);
        return 1;
    }
    else {
        // printf("%d not number\n", input[location] - 48);
        return 0;
    }
}

int check_glob (int from) {
    // int fromIsNumber = is_number(from);
    int globLength = 0;
    int nextIsNum = 1;
    int currentLoaction = from;
    while (nextIsNum == 1) {
        nextIsNum = is_number(currentLoaction + 1);
        globLength++;
        currentLoaction++;
    }
    // printf("glob length = %d ; exiting\n", globLength);

    return globLength;
}