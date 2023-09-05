#include <stdio.h>
#include <time.h>
#include <windows.h>
#define STAR_COUNT 80
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

HANDLE wHnd;
CHAR_INFO consoleBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];
COORD bufferSize = {SCREEN_WIDTH, SCREEN_HEIGHT};
COORD characterPos = {0, 0};
SMALL_RECT windowSize = {0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1};

HANDLE rHnd;
DWORD fdwMode;
DWORD numEvents = 0;
DWORD numEventsRead = 0;

bool play = true;
COORD star[STAR_COUNT];
const int SHIP_LENGTH = 5;
const char SHIP[SHIP_LENGTH + 1] = "<-0->";
const int SHIP_X_PADDING = SHIP_LENGTH / 2;
COORD shipPosition;
WORD shipColor = 7;


void setMode();
void setConsole(int x, int y);
void clear_buffer();
void fill_buffer_to_console();
void init_star();
void star_fall();
void draw_star_to_buffer();
void update_ship_position(int x, int y);
void randomize_ship_color();
void draw_ship_to_buffer(int x, int y);
bool check_ship_collision(int x, int y);
void assignment1();

int main() {
    int i = 0;
    srand(time(NULL));
    setConsole(SCREEN_WIDTH, SCREEN_HEIGHT);
    setMode(); 
    init_star();

    // assignment1();
    // Sleep(5000);

    // while (i < 1000) {
    //     star_fall();
    //     clear_buffer();
    //     draw_star_to_buffer();
    //     fill_buffer_to_console();
    //     Sleep(200);
    //     i++;
    // }

    while (play) {
        clear_buffer();

        // Handle input
        GetNumberOfConsoleInputEvents(rHnd, &numEvents);
        if (numEvents != 0) {
            INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
            ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
            for (DWORD i = 0; i < numEventsRead; ++i) {
                if (eventBuffer[i].EventType == KEY_EVENT &&
                    eventBuffer[i].Event.KeyEvent.bKeyDown == true) {
                    if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {
                        play = false;
                    }
                    else if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 'c') {
                        // randomize color on c pressed
                        randomize_ship_color();
                    }
                    // printf("press : %c\n", eventBuffer[i].Event.KeyEvent.uChar.AsciiChar);
                } else if (eventBuffer[i].EventType == MOUSE_EVENT) {
                    int mousePosX = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
                    int mousePosY = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
                    if (eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
                        // randomize color on left click
                        // printf("left click\n");
                        randomize_ship_color();
                    } else if (eventBuffer[i].Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) {
                        // printf("right click\n");
                    } else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED) {
                        // printf("mouse position : (%d,%d)\n", mousePosX, mousePosY);
                        update_ship_position(mousePosX, mousePosY);
                    }
                }
            }
            delete[] eventBuffer;
        } 
        // End handle inputs

        // Update frame
        draw_ship_to_buffer(shipPosition.X, shipPosition.Y);
        star_fall();
        draw_star_to_buffer();
        
        // Draw frame
        fill_buffer_to_console();

        Sleep(50);
    }


    return 0;
}

void setMode() {
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    SetConsoleMode(rHnd, fdwMode);
}

void setConsole(int x, int y) {
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
}

void clear_buffer() {
    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        for (int x = 0; x < SCREEN_WIDTH; ++x) {
            consoleBuffer[x + SCREEN_WIDTH * y].Char.AsciiChar = ' ';
            consoleBuffer[x + SCREEN_WIDTH * y].Attributes = 7;
        }
    }
}

void fill_buffer_to_console() {
    WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,
                        &windowSize);
}

void init_star() {
    for (int i = 0; i < STAR_COUNT; i++) {
        star[i].X = rand() % SCREEN_WIDTH;
        star[i].Y = rand() % SCREEN_HEIGHT;
    }
}

void star_fall() {
    for (int i = 0; i < STAR_COUNT; i++) {
        if (star[i].Y >= SCREEN_HEIGHT - 1) {
            star[i].X = (rand() % SCREEN_WIDTH);
            star[i].Y = 1;
        } else {
            star[i].Y++;
        };
    }
}

void draw_star_to_buffer() {
    for (int i = 0; i < STAR_COUNT; i++) {
        consoleBuffer[star[i].X + SCREEN_WIDTH * star[i].Y].Char.AsciiChar = '*';
    }
}

void update_ship_position(int x, int y) {
    if (x > (SCREEN_WIDTH - SHIP_X_PADDING - 1)) {
        x = SCREEN_WIDTH - SHIP_X_PADDING - 1;
    }
    else if (x < SHIP_X_PADDING) {
        x = SHIP_X_PADDING;
    }

    if (y > SCREEN_HEIGHT - 1) {
        y = SCREEN_HEIGHT - 1;
    }
    shipPosition.X = x;
    shipPosition.Y = y;
}

void randomize_ship_color() {
    shipColor = rand() % 65535;
}

void draw_ship_to_buffer(int x, int y) {
    int halfShipLength = SHIP_LENGTH / 2;
    for (int i = -halfShipLength; i <= halfShipLength; i++) {
        consoleBuffer[(x - i) + (SCREEN_WIDTH * y)].Char.AsciiChar = SHIP[i + halfShipLength];
        consoleBuffer[(x - i) + (SCREEN_WIDTH * y)].Attributes = shipColor;
    }
}

void assignment1() {
    for (int i = 0; i < 10000; i++) {
        for (int y = 0; y < SCREEN_HEIGHT; ++y) {
            for (int x = 0; x < SCREEN_WIDTH; ++x) {
                consoleBuffer[x + SCREEN_WIDTH * y].Char.AsciiChar = 'A';
                consoleBuffer[x + SCREEN_WIDTH * y].Attributes = rand() % 65535;
            }
        }

        setConsole(SCREEN_WIDTH, SCREEN_HEIGHT);
        fill_buffer_to_console();
    }
}
