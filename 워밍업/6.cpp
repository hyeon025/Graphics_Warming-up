#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>
#include <random>
#include <array>

using namespace std;

random_device rd;
default_random_engine dre{ rd() };
uniform_int_distribution uid{ 0,29 };

struct Board {
	int num{ 0 };
	bool obstacle{ false };
};

int p_x = 0;
int p_y = 0;

array<array<Board, 30>, 30> arr;

int main() {

	for (size_t i = 0; i < 4; i++){ //장애물 4개 뽑기
		int x = uid(dre);
		int y = uid(dre);

		if(arr[y][x].obstacle == false) {
			arr[y][x].obstacle = true;
		}
		else
			i--;
	}

	//보드판 출력
	for (size_t y = 0; y < 30; y++){
		for (size_t x = 0; x < 30; x++){

			if (x == p_x && y == p_y) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				cout << "*" << ' ';
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (!arr[y][x].obstacle) {
				if (arr[y][x].num != 0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				}
				cout << arr[y][x].num << ' ';
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << "X" << ' ';
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}

		}
		cout << endl;
	}

	//플레이어 위치

	while (true) {
		cout << "명령어 입력: ";

		string input;
		getline(cin, input);

		if (input.empty()) {
			p_x = 0;
			p_y = 0;

			for (size_t y = 0; y < 30; y++) { //보드판 리셋
				for (size_t x = 0; x < 30; x++) {
					arr[y][x].num = 0;
					arr[y][x].obstacle = false;
				}
			}

			for (size_t i = 0; i < 4; i++) { //장애물 4개 뽑기
				int x = uid(dre);
				int y = uid(dre);

				if (arr[y][x].obstacle == false) {
					arr[y][x].obstacle = true;
				}
				else
					i--;
			}

			system("cls"); //화면 지우기
			for (size_t y = 0; y < 30; y++) {
				for (size_t x = 0; x < 30; x++) {
					if (x == p_x && y == p_y) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
						cout << "*" << ' ';
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					}
					else if (!arr[y][x].obstacle) {
						if (arr[y][x].num != 0) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
						}
						cout << arr[y][x].num << ' ';
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

					}
					else {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
						cout << "X" << ' ';
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					}
				}
				cout << endl;
			}

			continue;
		}
		char c = input[0];

		switch (c) {
		case 'w': {
			if (p_y == 0 || arr[p_y - 1][p_x].obstacle)
				break;

			arr[p_y][p_x].num++;
			p_y--;
			break;
		}
		case 'a': {
			if (p_x == 0 || arr[p_y][p_x - 1].obstacle)
				break;

			arr[p_y][p_x].num++;
			p_x--;
			break;
		}
		case 's': {
			if (p_y == 29 || arr[p_y + 1][p_x].obstacle)
				break;

			arr[p_y][p_x].num++;
			p_y++;
			break;
		}
		case 'd': {
			if (p_x == 29 || arr[p_y][p_x + 1].obstacle)
				break;

			arr[p_y][p_x].num++;
			p_x++;
			break;
		}
		case 'q': {
			return 0;
		}
		}

		system("cls"); //화면 지우기

		for (size_t y = 0; y < 30; y++) {
			for (size_t x = 0; x < 30; x++) {

				if (x == p_x && y == p_y) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					cout << "*" << ' ';
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else if (!arr[y][x].obstacle) {
					if (arr[y][x].num != 0) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					}
					cout << arr[y][x].num << ' ';
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					cout << "X" << ' ';
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
			}
			cout << endl;
		}

	}

}