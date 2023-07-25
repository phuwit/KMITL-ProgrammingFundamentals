// VERY UNTESTED!!

#include <stdio.h>
#include <string.h>
#include <math.h>

int IsNum (int index);
int IsAlpha (int index);
int GetGlobLength (int fromIndex);
int StringToInt (int fromIndex, int Length);
int CharToInt (int index);

char input[100] = {'\0'};

int main() {
    scanf("%s", input);
    int inputLength = strlen(input);

    for (int i = 0; i < inputLength; i++) {
        if (IsNum(i) == 1) {
            int globLength = GetGlobLength(i);
            int globValue = StringToInt(i, globLength);
            // DEBUGWATCH globLength globValue
            for (int j; j <= globLength; j++) {
                printf("%c", input[i + globLength + 1]);
                // DEBUGWATCH j
            }
        }
    }
}

int IsNum (int index) {
    int asciiValue = (int)(input[index]);
    char DEBUGWATCH_charAtIndex = input[index];
    // DEBUGWATCH asciiValue
    if (asciiValue >= 48 && asciiValue <= 57) {
        return 1;
    }
    else {
        return 0;
    }
}

int IsAlpha (int index) {
    int asciiValue = (int)(input[index]);
    char DEBUGWATCH_charAtIndex = input[index];
    // DEBUGWATCH asciiValue
    if (asciiValue >= 65 && asciiValue <= 90 ||
        asciiValue >= 97 && asciiValue <= 122) {
        return 1;
    }
    else {
        return 0;
    }
}

int GetGlobLength (int fromIndex) {
    int globLength = 0;
    while (IsNum(fromIndex + globLength) == 1) {
        if (IsNum(fromIndex + globLength + 1) == 1) {
            globLength++;
        }
        else {
            break;
        }
        // DEBUGWATCH globLength after loop
    }
    return globLength;
}

int StringToInt (int fromIndex, int Length) {
    int coefficient = Length;
    int sum = 0;
    for (int i = fromIndex; i <= fromIndex + Length; i++) {
        int digitValue = CharToInt(i);
        int valueWithCoefficient = ((int)(pow(10, coefficient))) * digitValue;
        sum += valueWithCoefficient;
        // DEBUGWATCH digitValue valueWithCoefficient sum; after loop
    }
    return sum;
}

int CharToInt (int index) {
    int result = ((int)(input[index])) - 48;
    // DEBUGWATCH result
    return result;
}
