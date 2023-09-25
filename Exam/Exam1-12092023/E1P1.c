// check if it is a right triangle

#include <stdio.h>
#include <math.h>

int get_max_int_from_aray(int* array);
int* remove_int_from_aray(int* array);

int main () {
    int sides[3];
    for (int i = 0; i < 3; i++) {
        scanf(" %d", &sides[i]);
    }

    // get max int
    int max = sides[0];
    for (int i = 0; i < 3; i++) {
        if (max < sides[i]) {
            max = sides[i];
        }
    }

    // remove max int from array
    int sidesNoMax[2];
    int sidesNoMaxIndex = 0;
    for (int i = 0; i < 3; i++) {
        if (max != sides[i]) {
            sidesNoMax[sidesNoMaxIndex] = sides[i];
            sidesNoMaxIndex++;
        }
    }

    int ab_sq = 0;
    int c_sq = (int)(pow(max, 2));

    for (int i = 0; i < 2; i++) {
        ab_sq += (int)(pow(sidesNoMax[i], 2));
    }

    char isEqual = 'F';

    if (ab_sq == c_sq) {
        isEqual = 'T';
    }

    if (isEqual == 'T') {
        printf("Yes");
    }
    else {
        printf("No");
    }
}

int get_max_int_from_aray(int* array) {
    
}

int* remove_int_from_aray(int* array) {

}
