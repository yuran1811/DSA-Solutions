#include <windows.h>
#include <iostream>
#include <iostream>
#include <vector>
#include <conio.h>
#include <ctime>

#define sz(x) (int) x.size()

using namespace std;

const int WTH = 60, HGT = 30;
const char BD = 'o', APPLE = '@';

struct POS {
	int x, y;
	char c;

	bool operator == (const POS &a) const { return a.x == x && a.y == y; }
};
POS apple, prevTail;

vector <POS> snake, init = {
	POS{ WTH / 2 + 1, HGT / 2, BD },
	POS{ WTH / 2, HGT / 2, BD },
	POS{ WTH / 2 - 1, HGT / 2, BD }
};

enum class Dir { up, right, down, left };
Dir direction = Dir::right;

int score = 0, speed = 200;

void drawSnakePart(POS);
void drawHeadnTail();
void drawSnake();
void drawBox();

void ShowConsoleCursor(bool);
void Goto(int, int);
void displayScore();
void move();

void genApple();
void growing();

void startGame();
void INIT();

void ShowStartMenu();
void ShowEndMenu();

bool isBiteItself();
bool isAteApple();
bool isHitWall();

int main() { ShowStartMenu(); return 0; }

bool isHitWall()  { return !snake[0].x || !snake[0].y || snake[0].x == WTH || snake[0].y == HGT; }
bool isAteApple() { return snake[0] == apple; }

void drawSnake() { for (int i = 0; i < sz(snake); i++) drawSnakePart(snake[i]); }
void displayScore() { Goto(WTH + 3, 2); cout << "Your Score: " << score; }
void drawSnakePart(POS p) { Goto(p.x, p.y); cout << p.c; }
void growing() { snake.push_back(prevTail); }

void drawBox()
{
	for (int i = 0; i < WTH; i++) cout << "v";

	Goto(0, HGT);
	for (int i = 0; i < WTH; i++) cout << "^";
	for (int i = 1; i < HGT; i++) Goto(0, i), cout << ">";
	for (int i = 1; i < HGT; i++) Goto(WTH, i), cout << "<";
}

void genApple()
{
	srand(time(0));
	int x = rand() % (WTH - 1) + 1;
	int y = rand() % (HGT - 1) + 1;

	apple = { x, y };
	Goto(x, y);

	cout << APPLE;
}

void ShowEndMenu()
{
	system("cls"); Goto(0, 0);

	cout << "End game!\nYour score: " << score << "\nStart New Game ([Y]): ";
	
	char option; cin >> option; option = tolower(option);

	if (option == 'y') INIT(), startGame(); 
	else cout << "\nThanks\n", exit(1);
}

void startGame()
{
	system("cls"); INIT();

	for (;;)
	{
		if (_kbhit())
		{
			char ch = _getch(); ch = tolower(ch);
			if (ch == 's' && direction != Dir::up)		direction = Dir::down;  else 
			if (ch == 'w' && direction != Dir::down) 	direction = Dir::up; 	else 
			if (ch == 'a' && direction != Dir::right) 	direction = Dir::left;  else 
			if (ch == 'd' && direction != Dir::left) 	direction = Dir::right; else 
			if (ch == 'q') {ShowEndMenu(); break;}
		}

		move();
		drawHeadnTail();

		if (isAteApple())
		{
			score++;
			displayScore();
			growing();
			genApple();
		}

		if (isBiteItself() || isHitWall())
		{
			ShowConsoleCursor(true);
			ShowEndMenu();
			break;
		}

		Sleep(speed);
	}
}

void INIT()
{
	score = 0; 
	snake = init;
	direction = Dir::right;
	drawBox(); drawSnake(); 
	ShowConsoleCursor(false); 
	genApple(); displayScore();
}

void ShowStartMenu()
{
	system("cls");
	cout << "Welcome!\nOptions:\n   #1. Start\n   #2. Quit\nYour choice is: ";

	int option; cin >> option;
	if (option != 1) exit(1);
	system("cls"); cout << "Choose your level (1 - 5): ";
	int level, Time = 3; cin >> level; speed = 600 - level * 100;

	system("cls"); cout << "Tip: Press 'Q' to quit Game";
	
	Goto(0, 2); cout << "Ready!"; Sleep(1000);
	while (Time) Goto(0, 2), cout << Time-- << "      ", Sleep(1000);
	Goto(0, 2); cout << "GO!"; Sleep(1000); startGame();
}

void move()
{
	prevTail = snake.back();
	for (int i = sz(snake) - 1; i > 0; i--) snake[i] = snake[i - 1];
	if (direction == Dir::up) 	 snake[0].y -= 1; else 
	if (direction == Dir::down)  snake[0].y += 1; else 
	if (direction == Dir::left)	 snake[0].x -= 1; else 
	if (direction == Dir::right) snake[0].x += 1;
}

void drawHeadnTail()
{
	Goto(snake[0].x, snake[0].y); cout << snake[0].c;
	Goto(prevTail.x, prevTail.y); cout << ' ';
}

bool isBiteItself()
{
	POS head = snake[0];
	for (int i = 1; i < sz(snake); i++)
		if (head == snake[i]) return true;
	return false;
}

void Goto(int x, int y)
{
	COORD coord; coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}