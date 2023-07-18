#include <stdio.h>

int main () {
    const int START = 2;
    const int END = 100;

    int n[END + 1];

    for (int i = START; i <= END; i++) {
        n[i] = i;
    }

    for (int i = START; i <= END; i++) {
        int j = START + 1;
        int toIgnore = n[i] * 2;
        if (n[i] != -1) {
            while (toIgnore <= END) {
                n[toIgnore] = -1;
                toIgnore = n[i] * j;
                j++;
            }
        }
    }

    for (int i = START; i <= END; i++) {
        if (n[i] != -1) {
            printf("%d, ", n[i]);
        }
    }
}