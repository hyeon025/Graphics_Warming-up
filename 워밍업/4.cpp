#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>
#include <random>

using namespace std;

random_device rd;
default_random_engine dre{ rd() };

string str = "abcdefghijkl";

struct Board {
	char alpha{};
	bool match{ false };
	bool j_match{ false };
};
vector<Board> board;
//int matchcnt = 0;

int main() {

	for(char c : str) {
		board.push_back({c, false, false});
		board.push_back({c, false, false});
	}
	board.push_back({'@', false, false});

	shuffle(board.begin(), board.end(), dre);

	int count = 20;
	int score = 0;

	string input1, input2;
	while (count > 0) {
		//���� ���� ���
		system("cls"); //ȭ�� �����
		cout << "======score :" << score << "====== " << endl;
		for (int i = 0; i < 6; i++) {

			if (i != 0) {
				cout << i << '\t';
			}
			else
				cout << '\t';

			for (int j = 0; j < 5; j++) {
				if (i == 0) {
					cout << char('a' + j) << '\t';

				}
				else {
					if (board[(i - 1) * 5 + j].match) {
						/*board[(i - 1) * 5 + j].alpha = toupper(board[(i - 1) * 5 + j].alpha);*/
						int color{};
						if (!board[(i - 1) * 5 + j].j_match) {
							board[(i - 1) * 5 + j].alpha = toupper(board[(i - 1) * 5 + j].alpha);
							color = static_cast<int>(board[(i - 1) * 5 + j].alpha - 'A' + 1);
							if (color == 7)
								color = 13;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
						}
						else {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
						}
						cout << board[(i - 1) * 5 + j].alpha << '\t';
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					}
					else
						cout << '*' << '\t';
				}
			}
			cout << endl << endl;
		}
		cout << "==========================" << endl;

		//�Է¹ޱ�
		cout << "�Է�:";
		cin >> input1;
		if (input1 == "r") {
			score = 0;

			shuffle(board.begin(), board.end(), dre);

			for (size_t i = 0; i < 25; i++) {
				board[i].match = false;
				board[i].j_match = false;
			}
			continue;
		}
		else if (input1 == "h") {
			system("cls"); //ȭ�� �����
			cout << "==========================" << endl;
			for (int i = 0; i < 6; i++) {

				if (i != 0) {
					cout << i << '\t';
				}
				else
					cout << '\t';

				for (int j = 0; j < 5; j++) {
					if (i == 0) {
						cout << char('a' + j) << '\t';

					}
					else {
						if (board[(i - 1) * 5 + j].match) {	
							int color{};
							if (!board[(i - 1) * 5 + j].j_match) {
								color = static_cast<int>(board[(i - 1) * 5 + j].alpha - 'A' + 1);
								if (color == 7)
									color = 13;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
							}
							else {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
							}
							cout << board[(i - 1) * 5 + j].alpha << '\t';
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						}
						else
							cout << board[(i - 1) * 5 + j].alpha << '\t';
					}
				}
				cout << endl << endl;
			}
			cout << "==========================" << endl;
			Sleep(2000);
			continue;
		}
		else if(input1 == "q") {
			break;
		}
		else {
			cin >> input2;
		}
		
		if(input1.size() != 2 || input2.size() != 2) {
			cout << "�߸��� �Է��Դϴ�." << endl;
			Sleep(800);
			continue;
		}
		system("cls"); //ȭ�� �����
		char col1 = tolower(static_cast<char>(input1[0]));
		char row1 = input1[1];

		char col2 = tolower(static_cast<char>(input2[0]));
		char row2 = input2[1];

		if (col1 < 'a' || col1 > 'e' || col2 < 'a' || col2 > 'e' || row1 < '1' || row1 > '5' || row2 < '1' || row2 > '5') {
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}

		//�ε��� ���
		int c = col1 - 'a';
		int r = row1 - '1';
		int idx1 = r * 5 + c;

		c = col2 - 'a';
		r = row2 - '1';
		int idx2 = r * 5 + c;

		if(idx1 == idx2) {
			cout << "���� ��ġ�Դϴ�." << endl;
			continue;
		}
		if (board[idx1].match || board[idx2].match) {
			cout << "�̹� ���� ��ġ�Դϴ�." << endl;
			continue;
		}

		if (board[idx1].alpha == board[idx2].alpha) {
			board[idx1].match = true;
			board[idx2].match = true;
			board[idx1].alpha = toupper(static_cast<unsigned char>(board[idx1].alpha));
			board[idx2].alpha = toupper(static_cast<unsigned char>(board[idx2].alpha));
			score += 100;
			count--;
			cout << "¦ ����" << endl;
		}
		else if(board[idx1].alpha == '@' || board[idx2].alpha == '@') {
			board[idx1].match = true;
			board[idx2].match = true;
			board[idx1].j_match = true;
			board[idx2].j_match = true;
			if(isalpha(board[idx1].alpha))
				board[idx1].alpha = toupper(static_cast<unsigned char>(board[idx1].alpha));
			else if (isalpha(board[idx2].alpha))
				board[idx2].alpha = toupper(static_cast<unsigned char>(board[idx2].alpha));
			score += 100;
			count--;
			cout << "¦ ���� (��Ŀ)" << endl;
		}
		else { //Ʋ���� ���
			count--;
			cout << "¦ Ʋ��" << endl;
		}
		cout << "==========================" << endl;

		//������ ��� �����ֱ�

		for (int i = 0; i < 6; i++) {
			if (i != 0) {
				cout << i << '\t';
			}
			else
				cout << '\t';
			for (int j = 0; j < 5; j++) {
				if (i == 0) {
					cout << char('a' + j) << '\t';
				}
				else {
					if (board[(i - 1) * 5 + j].match) {
						int color{};
						if (!board[(i - 1) * 5 + j].j_match) {
							color = static_cast<int>(board[(i - 1) * 5 + j].alpha - 'A' + 1);
							if (color == 7)
								color = 13;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
						}
						else {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
						}
						cout << board[(i - 1) * 5 + j].alpha << '\t';
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					}
					/*else if (board[(i - 1) * 5 + j].open) {
						cout << board[(i - 1) * 5 + j].alpha << '\t';
					}*/
					else if ((i - 1) * 5 + j == idx1) {//��� �����ֱ�
						cout << board[(i - 1) * 5 + j].alpha << '\t';
					}
					else if ((i - 1) * 5 + j == idx2) {//��� �����ֱ�
						cout << board[(i - 1) * 5 + j].alpha << '\t';
					}
					else
						cout << '*' << '\t';
				}
			}
			cout << endl << endl;
		}
		cout << "==========================" << endl;
		Sleep(2000);
	}

}