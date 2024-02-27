#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<thread>
#include<chrono>
using namespace std;
int columnX = 10;
int columnY = 3;
bool gameOver = 0;
int birdY = 10;
void input() {
	if (_kbhit()) {
		if (_getch() == ' ')
		{
			birdY--;
		}
	}
}
void birdLogic() {
	while (!gameOver) {
		this_thread::sleep_for(chrono::milliseconds(600));
		birdY++;
		this_thread::sleep_for(chrono::milliseconds(200));
		birdY++;
	}
}
void logic() {
	

	if (birdY >= 20 || birdY <= 0) {
		gameOver = true;
	}
	
}
void draw() {
	system("cls");
	for (int y = 0; y < 20; y++)
	{
		if (y == birdY)
		{
			cout << "O";
		}
		for (int x = 0; x < 20; x++)
		{
			if (x == columnX)
			{
				cout << '#';
			}
			else {
				if (y != birdY) {
					cout << ' ';
				}
			}
		}
		cout << endl;
	}
	
	cout << "###################################################################################################################################################" << endl;
}
int main()
{
	thread decreaseThread(birdLogic); // Запускаем поток birdLogic
	while (!gameOver) {
		draw();
		input();
		logic();
	}
	decreaseThread.join(); // Дождемся завершения потока перед завершением программы
	return 0;
}