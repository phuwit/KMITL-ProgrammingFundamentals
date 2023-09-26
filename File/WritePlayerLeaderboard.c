#include <stdio.h>
#include <string.h>

int main () {
    const int PLAYER_COUNT = 5;
    struct Player {
        char name[100];
        int level;
        int score;
    };

    struct Player playerList[PLAYER_COUNT];
    for (int i = 0; i < PLAYER_COUNT; i++) {
        printf("Player %d Name : ", i + 1);
        scanf("%s", playerList[i].name);
        printf("Player %d Level : ", i + 1);
        scanf("%d", &playerList[i].level);
        printf("Player %d Score : ", i + 1);
        scanf("%d", &playerList[i].score);
    }
    
    FILE* fileptr;
    fileptr = fopen("leaderboard.csv", "w");


    printf("\nName\tLevel\tScore\n");
    fprintf(fileptr, "Name,Level,Score\n");
    for (int i = 0; i < PLAYER_COUNT; i++) {
        printf("%s\t", playerList[i].name);
        printf("%d\t", playerList[i].level);
        printf("%d\n", playerList[i].score);
        fprintf(fileptr, "%s,%d,%d\n", playerList[i].name, playerList[i].level, playerList[i].score);
    }

    fclose(fileptr);
    return 0;
}