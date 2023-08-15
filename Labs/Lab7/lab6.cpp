#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void setcursor(bool visible);
void setcolor(int fg, int bg);
void gotoxy(int x, int y);
void draw_ship(int x, int y);
void erase_ship(int x, int y);
void draw_bullet(int x, int y);
void erase_bullet(int x, int y);

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

    char ch = '\0';
    char lastPressed = ch;
    int x = SCREEN_WIDTH - (SHIP_LENGTH / 2), y = 20;
    int bulletsX[MAX_BULLETS], bulletsY[MAX_BULLETS];
    for (int i = 0; i < MAX_BULLETS; i++) {
        bulletsX[i] = -1;
        bulletsY[i] = -1;
    }
    int bulletsInFlight = 0;
    draw_ship(x, y);
    // move left/ right
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
                    erase_bullet(bulletsX[i], bulletsY[i]);
                    bulletsY[i]--;
                    draw_bullet(bulletsX[i], bulletsY[i]);
                }

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
}

void erase_bullet(int x, int y) {
    // set a color to black, black
    setcolor(0, 0);
    gotoxy(x, y);
    printf(" ");
}
