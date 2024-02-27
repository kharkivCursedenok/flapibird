#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<thread>
#include<chrono>
using namespace std;
int score = 0;
int columnX = 15;
int columnY = 0;
bool gameOver = 0;
int birdY = 10;
void input() {
	if (_kbhit()) {
		if (_getch() == ' ')
		{
			for (int i = 0; i < 2; ++i) {
				birdY--;
				this_thread::sleep_for(chrono::milliseconds(50));
			}
		}
	}
}
void moveLogic() {
	while (!gameOver) {
		this_thread::sleep_for(chrono::milliseconds(300));
		birdY++;
		columnX--;
		this_thread::sleep_for(chrono::milliseconds(200));
		birdY++;
		columnX--;
	}
	
}
void logic() {
	if (birdY >= 19 || birdY < 0) {
		cout << "DENIS LOX";
		gameOver = true;
	}

	if (columnX == 1 && columnY != birdY && columnY+1 != birdY && columnY-1 != birdY && columnY + 2 != birdY && columnY - 2 != birdY )
	{
		cout << "DENIS LOX";
		gameOver = true;
	}
	
}
void draw() {
	system("cls");
	for (int y = 0; y < 20; y++) {
		if (y == birdY) {
			cout << "O";
			for (int x = 1; x < 20; x++) {
				if (x == columnX && y != columnY && y != columnY - 1 && y != columnY + 1 && y != columnY - 2 && y != columnY + 2) {
					cout << '#';
				}
				else {
					cout << ' ';
				}
			}
		}
		else {
			for (int x = 0; x < 20; x++) {
				if (x == columnX && y != columnY && y != columnY - 1 && y != columnY + 1 && y != columnY - 2 && y != columnY + 2) {
					cout << '#';
				}
				else {
					cout << ' ';
				}
			}
		}
		cout << endl;
	}

	cout << "################################################################" << endl;
	cout << endl << score << endl;
}
int main()
{
	thread inputThread(input);
	thread decreaseThread(moveLogic); 
	while (!gameOver) {
		input();
		draw();
		logic();
		if (columnX < 0) {
			srand(time(NULL));
			columnY = rand() % 20;
			columnX = 15;
			score++;
		}
	}
	decreaseThread.join(); 
	inputThread.join();
	return 0;
}