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

struct Rect {
	int x;
	int y;
	int width; //x
	int height; //y
};

Rect rects[2];
int rectnum = 0;
int boardWidth = 30; //x
int boardHeight = 30; //y
array<array<char, 40>, 40> board{};

int choice() {
	cout << "사각형 선택(1 or 2): ";
	int num{};
	cin >> num;
	if (num != 1 && num != 2) {
		cout << "잘못된 입력입니다." << endl;
		Sleep(800);
		return -1;
	}
	return num - 1;
}

int main() {
	
	for (auto& c : board) {
		c.fill('.');
	}
	for (size_t y = 0; y < boardHeight; y++) {
		for (size_t x = 0; x < boardWidth; x++) {
			cout << board[y][x] << ' ';
		}
		cout << endl;
	}
	while(true) {

		cout << "명령어 입력: ";
		string line;
		if (!getline(cin, line)) 
			break;
		if (line.empty())
			continue;

		istringstream iss(line);
		vector<string> tokens;
		string tok;
		while (iss >> tok) {
			tokens.push_back(tok);
		}
		if (tokens.size() != 1 && tokens.size() != 4) {
			cout << "잘못된 입력입니다." << endl;
			Sleep(800);
			continue;
		}

		if(tokens.size() == 4) {
			int x = stoi(tokens[0]);
			int y = stoi(tokens[1]);
			int x2 = stoi(tokens[2]);
			int y2 = stoi(tokens[3]);

			if (x <0 || x>boardWidth || y<0 || y>boardHeight || x2<0 || x2>boardWidth || y2<0 || y2>boardHeight) {
				cout << "보드판 안의 숫자를 입력하세요." << endl;
				Sleep(800);
				continue;
			}
			if (x2 <= x || y2 <= y) {
				cout << "가로, 세로 길이는 0보다 커야 합니다." << endl;
				Sleep(800);
				continue;
			}
			int width = x2 - x;
			int height = y2 - y;

			if (rectnum < 2)
				rects[rectnum++] = { x, y, width, height };
			else {
				cout << "더 이상 사각형을 그릴 수 없습니다." << endl;
				Sleep(800);
				continue;
			}


		}
		else{
			char cmd = tokens[0][0];

			if (!isalpha((unsigned char)cmd)) {
				cout << "잘못된 입력입니다." << endl;
				Sleep(800);
				continue;
			}

			switch (cmd) {
			case 'x': { //우측 이동 
				int num{};
				if(rectnum == 0) {
					cout << "사각형이 없습니다." << endl;
					Sleep(800);
					break;
				}
				else if(rectnum == 1) {
					num = 0;
				}
				else
					num = choice();

				if (num != -1) {
					rects[num].x += 1;
				}
				if (rects[num].x > boardWidth - 1) {
					rects[num].x = 0;
				}
				break;
			}
			case 'X': { //좌측 이동
				int num{};
				if (rectnum == 0) {
					cout << "사각형이 없습니다." << endl;
					Sleep(800);
					break;
				}
				else if (rectnum == 1) {
					num = 0;
				}
				else
					num = choice();

				if (num != -1) {
					rects[num].x -= 1;
				}
				if(rects[num].x < 0) {
					rects[num].x = boardWidth - 1;
				}
				break;
			}
			case 'y': { //아래 이동
				int num{};
				if (rectnum == 0) {
					cout << "사각형이 없습니다." << endl;
					Sleep(800);
					break;
				}
				else if (rectnum == 1) {
					num = 0;
				}
				else
					num = choice();

				if(num != -1) {
					rects[num].y += 1;
				}
				if(rects[num].y >= boardHeight) {
					rects[num].y = 0;
				}

				break;
			}
			case 'Y': { //위 이동
				int num{};
				if (rectnum == 0) {
					cout << "사각형이 없습니다." << endl;
					Sleep(800);
					break;
				}
				else if (rectnum == 1) {
					num = 0;
				}
				else
					num = choice();

				if(num != -1) {
					rects[num].y -= 1;
				}
				if(rects[num].y < 0) {
					rects[num].y = boardHeight - 1;
				}
				break;
			}
			case 's': { //모두 한 칸 축소
				int num{};
				if (rectnum == 0) {
					cout << "사각형이 없습니다." << endl;
					Sleep(800);
					break;
				}
				else if (rectnum == 1) {
					num = 0;
				}
				else
					num = choice();

				if (num != -1) {
					if(rects[num].width > 1 && rects[num].height > 1) {
						rects[num].width -= 1;
						rects[num].height -= 1;
					}
					else {
						cout << "더 이상 축소할 수 없습니다." << endl;
						Sleep(800);
					}
				}
				break;
			}
			case 'S': { //모두 한 칸 확대
				int num{};
				if (rectnum == 0) {
					cout << "사각형이 없습니다." << endl;
					Sleep(800);
					break;
				}
				else if (rectnum == 1) {
					num = 0;
				}
				else
					num = choice();

				if (num != -1) {
					if (rects[num].width < boardWidth && rects[num].height < boardHeight) {
						rects[num].width += 1;
						rects[num].height += 1;
					}
					else {
						cout << "더 이상 확대할 수 없습니다." << endl;
						Sleep(800);
					}
				}
				break;
			}
			case 'i': { //x축 한 칸 확대
				int num{};
				if (rectnum == 0) {
					cout << "사각형이 없습니다." << endl;
					Sleep(800);
					break;
				}
				else if (rectnum == 1) {
					num = 0;
				}
				else
					num = choice();

				if (num != -1) {
					if (rects[num].width < boardWidth) {
						rects[num].width += 1;
					}
					else {
						cout << "더 이상 확대할 수 없습니다." << endl;
						Sleep(800);
					}
				}
				break;
			}
			case 'I': { //x축 한 칸 축소
				int num{};
				if (rectnum == 0) {
					cout << "사각형이 없습니다." << endl;
					Sleep(800);
					break;
				}
				else if (rectnum == 1) {
					num = 0;
				}
				else
					num = choice();

				if (num != -1) {
					if (rects[num].width > 1) {
						rects[num].width -= 1;
					}
					else {
						cout << "더 이상 축소할 수 없습니다." << endl;
						Sleep(800);
					}
				}
				break;
			}
			case 'j': { //y축 한 칸 확대
				int num{};
				if (rectnum == 0) {
					cout << "사각형이 없습니다." << endl;
					Sleep(800);
					break;
				}
				else if (rectnum == 1) {
					num = 0;
				}
				else
					num = choice();

				if (num != -1) {
					if (rects[num].height < boardHeight) {
						rects[num].height += 1;
					}
					else {
						cout << "더 이상 확대할 수 없습니다." << endl;
						Sleep(800);
					}
				}
				break;
			}
			case 'J': { //y축 한 칸 축소
				int num{};
				if (rectnum == 0) {
					cout << "사각형이 없습니다." << endl;
					Sleep(800);
					break;
				}
				else if (rectnum == 1) {
					num = 0;
				}
				else
					num = choice();

				if (num != -1) {
					if (rects[num].height > 1) {
						rects[num].height -= 1;
					}
					else {
						cout << "더 이상 축소할 수 없습니다." << endl;
						Sleep(800);
					}
				}
				break;
			}
			case 'a': { //x축 한 칸 확대, y축 한 칸 축소
				int num{};
				if (rectnum == 0) {
					cout << "사각형이 없습니다." << endl;
					Sleep(800);
					break;
				}
				else if (rectnum == 1) {
					num = 0;
				}
				else
					num = choice();

				if (num != -1) {
					if (rects[num].width < boardWidth && rects[num].height > 1) {
						rects[num].width += 1;
						rects[num].height -= 1;
					}
					else {
						cout << "더 이상 확대/축소할 수 없습니다." << endl;
						Sleep(800);
					}
				}
				break;
			}
			case 'A': { //x축 한 칸 축소, y축 한 칸 확대
				int num{};
				if (rectnum == 0) {
					cout << "사각형이 없습니다." << endl;
					Sleep(800);
					break;
				}
				else if (rectnum == 1) {
					num = 0;
				}
				else
					num = choice();

				if (num != -1) {
					if (rects[num].width > 1 && rects[num].height < boardHeight) {
						rects[num].width -= 1;
						rects[num].height += 1;
					}
					else {
						cout << "더 이상 확대/축소할 수 없습니다." << endl;
						Sleep(800);
					}
				}
				break;
			}
			case 'b': { //사각형 면적 출력
				int num{};
				if (rectnum == 0) {
					cout << "사각형이 없습니다." << endl;
					Sleep(800);
					break;
				}
				else if (rectnum == 1) {
					num = 0;
				}
				else
					num = choice();
				if (num != -1) {
					cout<< "사각형 " << num + 1 << "의 면적: " << rects[num].width * rects[num].height << endl;
					Sleep(800);
				}
				break;
			}
			case 'c': { //보드칸 x,y 한 칸씩 늘리기 (최대 10칸 늘리기 가능)
				if(boardWidth >= 39 || boardHeight >= 39) {
					cout << "더 이상 보드칸을 늘릴 수 없습니다." << endl;
					Sleep(800);
					break;
				}
				boardWidth += 1;
				boardHeight += 1;
				break;
			}
			case 'd': { //보드칸 x,y 한 칸씩 줄이기 (최대 20칸 줄이기 가능 but 도형은 보드칸 안에)
				if (boardWidth <= 10 || boardHeight <= 10 || rects[0].width >= boardWidth || rects[0].height >= boardHeight) {
					cout << "더 이상 보드칸을 줄일 수 없습니다." << endl;
					Sleep(800);
					break;
				}
				boardWidth -= 1;
				boardHeight -= 1;

				break;
			}
			case 'r': { //모두 리셋
				boardWidth = 30;
				boardHeight = 30;
				for (auto& c : board) {
					c.fill('.');
				}
				rects[0] = { 0,0,0,0 };
				rects[1] = { 0,0,0,0 };
				rectnum = 0;
				break;
			}
			case 'q': { //종료
				return 0;
			}
			}
		}

		int num{};
		//보드판 설정

		for (auto& c : board) {
			c.fill('.');
		}

		for (int y = 0; y < boardHeight; y++) {
			for (int x = 0; x < boardWidth; x++) {
				//사각형 그리기
				for (int r = 0; r < rectnum; r++) {
					char mark = (r == 0 ? 'O' : 'X');
					for (int i = rects[r].y; i < rects[r].y + rects[r].height; i++) {
						for (int j = rects[r].x; j < rects[r].x + rects[r].width; j++) {
							int yy = (i + boardHeight) % boardHeight;
							int xx = (j + boardWidth) % boardWidth;
							if (board[yy][xx] == '.') {
								board[yy][xx] = mark;
							}
							else if (board[yy][xx] != mark) {
								board[yy][xx] = '#';
							}
						}
					}
				}

			}
			if (num == rectnum) {
				break;
			}
		}
		//보드판 출력
		system("cls"); //화면 지우기
		for (size_t y = 0; y < boardHeight; y++) {
			for (size_t x = 0; x < boardWidth; x++) {
				cout << board[y][x] << ' ';
			}
			cout << endl;
		}

	}

}