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
		cout << "��ɾ� �Է�:";
		getline(cin, input);

		switch (input[0]) {
		case '+': {
			if (data_num == list.size()) {
				cout << "����Ʈ�� ��ĭ�� �����ϴ�." << endl;
				break;
			}

			stringstream ss(input.substr(2));
			int a{};

			if (!list[list.size() - 1].exi) { //������ ������� ���
				for (int i = list.size() - 1; i >= 0; --i) {
					if (list[i].exi) {
						a = i + 1;
						break;
					}
				}
			}
			else { //������ ������ ���
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
				cout << "����Ʈ�� ��ĭ�� �����ϴ�." << endl;
				break;
			}
			stringstream ss(input.substr(2));
			int a{};

			if (!list[0].exi) { //�Ʒ��� ������� ���
				ss >> list[0].x >> list[0].y >> list[0].z;
				list[0].exi = true;
				++data_num;
			}
			else { //�Ʒ��� ������ ���
				for (size_t i = 0; i < list.size(); ++i) { //��ĭ ã��
					if (!list[i].exi) {
						a = i;
						break;
					}
				}

				for (size_t i = a; i > 0; --i) //��ĭ���� �� �Ʒ����� �����
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
		case 'a': { //�� ���� ���
			cout << "����� �� ���� :" << data_num << endl;
			break;
		}
		case 'b': { //�ε��� �б�
			Data data{};
			data = list[0];
			for (size_t i = 0; i < 9; i++) {
				list[i] = list[i + 1];
			}
			list[9] = data;

			print_list(list);
			break;
		}
		case 'c': {	//����Ʈ ����
			list.fill(init);
			data_num = 0;
			print_list(list);
			break;
		}
		case 'f': { //�������� �Ÿ��� �ε��� 0���ͷ� �������� ���� (��۷�)
			if (!click_f) {
				save_list = list;
				sort(list.begin(), list.end(), compare);
				print_list(list);
				click_f = true;
			}
			else { //�������
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
			cout << "�߸��� �Է��Դϴ�." << endl;
			print_list(list);
		}
		}
	}
	

}