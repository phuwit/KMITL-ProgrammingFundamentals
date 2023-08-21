#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

void setcursor(bool visible);
void setcolor(int fg, int bg);
void gotoxy(int x, int y);
char cursor(int x, int y);
void draw_ship(int x, int y);
void erase_ship(int x, int y);
void draw_bullet(int x, int y);
void erase_bullet(int x, int y);
void draw_random_stars(int starCount);
void display_score(int score, char* scoreIncrease);

const int SHIP_LENGTH = 7;
const int SHIP_WIDTH = 1;
const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 24;
const int MAX_BULLETS = 5;

int main() {
    // clear screen
    system("cls");
    // hide cursor
    setcursor(false);
    setcolor(0, 0);

    srand(time(0));

    char ch = '\0';
    char lastPressed = ch;
    int x = SCREEN_WIDTH - (SHIP_LENGTH / 2), y = 20;
    int bulletsX[MAX_BULLETS], bulletsY[MAX_BULLETS];
    for (int i = 0; i < MAX_BULLETS; i++) {
        bulletsX[i] = -1;
        bulletsY[i] = -1;
    }
    int bulletsInFlight = 0;

    int score = 0;
    char scoreIncrease = 'F';

    draw_ship(x, y);
    draw_random_stars(20);
    do {
        // handle input
        if (_kbhit()) {
            ch = _getch();
            if (ch == 'a' || ch == 'd' || ch == 's') lastPressed = ch;
            if (ch == 's') lastPressed = '\0';
            if (ch == ' ' && bulletsInFlight <= MAX_BULLETS) {
                bulletsInFlight++;
                for (int i = 0; i < MAX_BULLETS; i++) {
                    if (bulletsX[i] == -1 && bulletsY[i] == -1) {
                        bulletsX[i] = x + (SHIP_LENGTH / 2);
                        bulletsY[i] = y - 1;
                        break;
                    }
                }
            }
            fflush(stdin);
        }

        // update frame
        if (bulletsInFlight > 0) {
            for (int i = 0; i < MAX_BULLETS; i++) {
                if (bulletsX[i] != -1 && bulletsY[i] != -1) {
                    // check collisions
                    if (cursor(bulletsX[i], bulletsY[i] - 1) == '*') {
                        // hit a star, remove a bullet
                        Beep(1500, 200);
                        score++;
                        scoreIncrease = 'T';
                        draw_random_stars(1);
                        // remove star and bullet
                        erase_bullet(bulletsX[i], bulletsY[i] - 1);
                        erase_bullet(bulletsX[i], bulletsY[i]);
                        bulletsX[i] = -1;
                        bulletsY[i] = -1;
                        bulletsInFlight--;
                    } else {
                        erase_bullet(bulletsX[i], bulletsY[i]);
                        bulletsY[i]--;
                        draw_bullet(bulletsX[i], bulletsY[i]);
                    }
                }

                // remove OOB bullet
                if (bulletsY[i] == 0) {
                    erase_bullet(bulletsX[i], bulletsY[i]);
                    bulletsX[i] = -1;
                    bulletsY[i] = -1;
                    bulletsInFlight--;
                }
            }
        }

        if (lastPressed == 'a' && x > 0) {
            erase_ship(x, y);
            draw_ship(--x, y);
        }
        if (lastPressed == 'd' && x < SCREEN_WIDTH - SHIP_LENGTH) {
            erase_ship(x, y);
            draw_ship(++x, y);
        }
        if (lastPressed == ' ' && y < SCREEN_HEIGHT - SHIP_WIDTH) {
            erase_ship(x, y);
            draw_ship(x, ++y);
        }

        display_score(score, &scoreIncrease);

        Sleep(50);
        // exit
    } while (ch != 'x');
    return 0;
}

void setcursor(bool visible) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}

void setcolor(int fg, int bg) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void gotoxy(int x, int y) {
    COORD c = {(short)x, (short)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

char cursor(int x, int y) {
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2];
    COORD c = {(short)x, (short)y};
    DWORD num_read;
    if (!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c,
                                    (LPDWORD)&num_read))
        return '\0';
    else
        return buf[0];
}

void draw_ship(int x, int y) {
    // set a color to green, red
    setcolor(2, 4);
    gotoxy(x, y);
    printf(" <-0-> ");
}

void erase_ship(int x, int y) {
    // set a color to black, black
    setcolor(0, 0);
    gotoxy(x, y);
    printf("       ");
}

void draw_bullet(int x, int y) {
    // set a color to lightblue, black
    setcolor(9, 0);
    gotoxy(x, y);
    printf("|");
    // Assignment 2
    // Beep(400, 20);
}

void erase_bullet(int x, int y) {
    // set a color to black, black
    setcolor(0, 0);
    gotoxy(x, y);
    printf(" ");
}

// lab7 assn1
void draw_random_stars(int starCount) {
    setcolor(7, 0);
    for (int i = 0; i < starCount; i++) {
        int y = rand() % 4 + 2;
        int x = rand() % 61 + 10;
        if (cursor(x, y) != '*') {
            gotoxy(x, y);
            printf("*");
        } else {
            i--;
        }
    }
}

void display_score(int score, char* scoreIncrease) {
    gotoxy(SCREEN_WIDTH - 12, 0);
    if (*scoreIncrease == 'T') {
        setcolor(14, 0);
        *scoreIncrease = 'F';
    } else {
        setcolor(6, 0);
    }
    printf("Score : %.4d", score);
}