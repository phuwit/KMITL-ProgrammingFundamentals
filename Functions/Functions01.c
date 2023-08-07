#include <stdio.h>
#include <string.h>

void removeLowerCase (char*, char*);

int main () {
    char input[100];
    scanf("%s", input);

    char output[strlen(input)];
    removeLowerCase(input, output);

    printf("%s", output);
}

void removeLowerCase (char* input, char* output) {
    int realInputLength = strlen(input);
    int outputCursor = 0;

    for (int i = 0; i < realInputLength; i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') {
            output[outputCursor] = input[i];
            outputCursor++;
        }
    }

    output[outputCursor] = '\0';
}