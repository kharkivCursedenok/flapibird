#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

bool gameOver = 0;
int birdY = 10;
enum DIRECTION { STOP = 0, JUMP };
DIRECTION dir;
void input() {
	if (_kbhit()) {
		if (_getch() == 'j')
		{
			birdY++;
			Sleep(1);
			birdY++;
		}
	}
}
void logic() {

}
void draw() {
	system("cls");
	for (int i = 0; i <= 20; i++)
	{
		cout << endl;
	}
	cout << "####################" << endl;
}
int main()
{
	while (!gameOver) {
		draw();
	}
	return 0;
}