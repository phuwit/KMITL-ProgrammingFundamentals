#include <stdio.h>
#include <windows.h> 

void gotoxy(int x, int y);
void draw_ship(int x, int y);

const int SHIP_LENGTH = 7;

int main()
{
	draw_ship(10, 5);
	return 0;
}

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y)
{
	gotoxy(x, y);
	printf(" <-0-> ");
}
