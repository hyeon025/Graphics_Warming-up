#include <iostream>
#include <array>
#include <sstream>
#include <algorithm>

using namespace std;



struct Data {
	int x{};
	int y{};
	int z{};
	bool exi{ false };

	double dist() {
		return sqrt(x * x + y * y + z * z);
	}
};

bool compare(Data& a, Data& b) {
	unsigned int a_num = numeric_limits<unsigned int>::min();
	unsigned int b_num = numeric_limits<unsigned int>::min();

	if (a.exi)
		a_num = a.dist();
	if (b.exi)
		b_num = b.dist();

	return a_num > b_num;

}

void print_list(array<Data,10>& data) {
	for (int i = data.size()-1; i >= 0;--i) {
		if (data[i].exi) {
			cout << data[i].x << ' ' << data[i].y << ' ' << data[i].z << ' ' << endl;
		}
		else
			cout << "------" << endl;
	}
}

array<Data, 10> list;
array<Data, 10> save_list;
int data_num = 0;
bool click_f = false;

int main() {
	string input{};

	Data init{ 0,0,false };
	

	while (true) {
		cout << "명령어 입력:";
		getline(cin, input);

		switch (input[0]) {
		case '+': {
			if (data_num == list.size()) {
				cout << "리스트에 빈칸이 없습니다." << endl;
				break;
			}

			stringstream ss(input.substr(2));
			int a{};

			if (!list[list.size() - 1].exi) { //위에가 비어있을 경우
				for (int i = list.size() - 1; i >= 0; --i) {
					if (list[i].exi) {
						a = i + 1;
						break;
					}
				}
			}
			else { //위에가 차있을 경우
				for (size_t i = 0; i < list.size(); ++i) {
					if (!list[i].exi) {
						a = i;
						break;
					}
				}
			}
			ss >> list[a].x >> list[a].y >> list[a].z;
			list[a].exi = true;
			++data_num;
			print_list(list);

			break;
		}
		case '-': {
			for (int i = list.size() - 1; i >= 0; --i) {
				if (list[i].exi) {
					list[i].exi = false;
					--data_num;
					break;
				}
			}
			print_list(list);
			break;
		}
		case 'e': {
			if (data_num == list.size()) {
				cout << "리스트에 빈칸이 없습니다." << endl;
				break;
			}
			stringstream ss(input.substr(2));
			int a{};

			if (!list[0].exi) { //아래가 비어있을 경우
				ss >> list[0].x >> list[0].y >> list[0].z;
				list[0].exi = true;
				++data_num;
			}
			else { //아래가 차있을 경우
				for (size_t i = 0; i < list.size(); ++i) { //빈칸 찾기
					if (!list[i].exi) {
						a = i;
						break;
					}
				}

				for (size_t i = a; i > 0; --i) //빈칸부터 맨 아래까지 땅기기
				{
					list[i] = list[i - 1];
				}
				ss >> list[0].x >> list[0].y >> list[0].z;
				list[0].exi = true;
				++data_num;
			}
			print_list(list);
			break;
		}
		case 'd': {
			for (size_t i = 0; i < list.size(); i++)
			{
				if (list[i].exi) {
					list[i].exi = false;
					--data_num;
					break;
				}
			}
			print_list(list);
			break;
		}
		case 'a': { //점 개수 출력
			cout << "저장된 점 개수 :" << data_num << endl;
			break;
		}
		case 'b': { //인덱스 밀기
			Data data{};
			data = list[0];
			for (size_t i = 0; i < 9; i++) {
				list[i] = list[i + 1];
			}
			list[9] = data;

			print_list(list);
			break;
		}
		case 'c': {	//리스트 비우기
			list.fill(init);
			data_num = 0;
			print_list(list);
			break;
		}
		case 'f': { //원점과의 거리로 인덱스 0부터로 오름차순 정렬 (토글로)
			if (!click_f) {
				save_list = list;
				sort(list.begin(), list.end(), compare);
				print_list(list);
				click_f = true;
			}
			else { //원래대로
				list = save_list;
				print_list(list);
				click_f = false;
			}
			break;
		}
		case 'q': {
			return 0;
		}
		default: {
			cout << "잘못된 입력입니다." << endl;
			print_list(list);
		}
		}
	}
	

}