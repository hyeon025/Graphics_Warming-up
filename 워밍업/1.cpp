#include <iostream>
#include <random>
#include <print>

using namespace std;

random_device rd;
default_random_engine dre{ rd() };
uniform_int_distribution uid{ 1,9 };

int matrix[2][4][4];
int cul_matrix[4][4];
int m_matrix[4][4];
bool e = false;
bool f = false;
int num_bool = 0;

void Make_matrix() 
{
	//행렬 두개 랜덤 수 배정
	cout << "======================" << endl;
	for (size_t i = 0; i < 2; i++){
		for (size_t j = 0; j < 4; j++){
			for (size_t k = 0; k < 4; k++){
				matrix[i][j][k] = uid(dre);
				cout << matrix[i][j][k]<<'\t';
			}
			cout << endl;
		}
		cout << "======================" << endl;
	}

}

long long Det2(long long a, long long b, long long c, long long d) {
	return a * d - b * c;
}

long long Det3(int m[3][3]) {
	return m[0][0] * Det2(m[1][1], m[1][2], m[2][1], m[2][2])
		- m[0][1] * Det2(m[1][0], m[1][2], m[2][0], m[2][2])
		+ m[0][2] * Det2(m[1][0], m[1][1], m[2][0], m[2][1]);
}

void make_m3(int a[4][4], int col, int out[3][3]) {
	int r = 0;
	for (size_t i = 1; i < 4; i++){
		int c = 0;
		for (size_t j = 0; j < 4; j++){
			if (j == col)
				continue;
			out[r][c++] = a[i][j];
		}
		++r;
	}
}

long long Det4(int a[4][4]) {
	int m3[3][3];
	long long s = 0;

	make_m3(a, 0, m3);
	s += (long long)a[0][0] * Det3(m3);
	make_m3(a, 1, m3);
	s -= (long long)a[0][1] * Det3(m3);
	make_m3(a, 2, m3);
	s += (long long)a[0][2] * Det3(m3);
	make_m3(a, 3, m3);
	s -= (long long)a[0][3] * Det3(m3);
	return s;
}

int main() {
	char input;

	Make_matrix();

	while (true) {
		cout << "명령어 입력:";
		cin >> input;

		switch (input) {
		case 'm': {
			int num = 0;

			for (size_t i = 0; i < 4; i++) {
				for (size_t j = 0; j < 4; j++) {
					for (size_t k = 0; k < 4; k++)
					{
						num += matrix[0][i][k] * matrix[1][k][j];
					}
					cul_matrix[i][j] = num;
					print("{}\t", cul_matrix[i][j]);
					num = 0;
				}
				cout << endl;
			}
			cout << "======================" << endl;

			break;
		}
		case 'a': {
			for (size_t i = 0; i < 4; i++){
				for (size_t j = 0; j < 4; j++){
					cul_matrix[i][j] = matrix[0][i][j] + matrix[1][i][j];
					print("{}\t",cul_matrix[i][j]);
				}
				cout << endl;
			}
			cout << "======================" << endl;

			break;
		}
		case 'd': {
			for (size_t i = 0; i < 4; i++) {
				for (size_t j = 0; j < 4; j++) {
					cul_matrix[i][j] = matrix[0][i][j] - matrix[1][i][j];
					print("{}\t", cul_matrix[i][j]);
				}
				cout << endl;
			}
			cout << "======================" << endl;

			break;
		}
		case 'r': {
			long long det1 = Det4(matrix[0]);
			long long det2 = Det4(matrix[1]);

			cout << "det1 = " << det1 << endl;
			cout << "det2 = " << det2 << endl;
			cout << "========================" << endl;
			break;
		}
		case 't': {
			for (int k = 0; k < 2; ++k) {
				for (int i = 0; i < 4; ++i) {
					for (int j = 0; j < 4; ++j) {
						print("{}\t", matrix[k][j][i]);
					}
					cout << '\n';
				}
				cout << "====================" << endl;
			}
			break;
		}
		case 'e': {
			if (!e) {
				e = true;
				int num[2]{};
				for (size_t k = 0; k < 2; k++) {
					int min = numeric_limits<int>::max();
					for (size_t i = 0; i < 4; i++) {
						for (size_t j = 0; j < 4; j++) {
							if (matrix[k][i][j] < min)
								min = matrix[k][i][j];
						}
					}
					num[k] = min;
				}

				for (size_t k = 0; k < 2; k++) {
					for (size_t i = 0; i < 4; i++) {
						for (size_t j = 0; j < 4; j++) {
							m_matrix[i][j] = matrix[k][i][j] - num[k];
							print("{}\t", m_matrix[i][j]);
						}
						cout << endl;
					}
					cout << "=================" << endl;
				}
			}
			else {
				e = false;
				for (size_t k = 0; k < 2; k++) {
					for (size_t i = 0; i < 4; i++) {
						for (size_t j = 0; j < 4; j++) {
							cout << matrix[k][i][j] << '\t';
						}
						cout << endl;
					}
					cout << "==================" << endl;
				}
			}
			break;
		}
		case 'f': {
			if (!f) {
				f = true;
				int num[2]{};
				for (size_t k = 0; k < 2; k++) {
					int max = numeric_limits<int>::min();
					for (size_t i = 0; i < 4; i++) {
						for (size_t j = 0; j < 4; j++) {
							if (matrix[k][i][j] > max)
								max = matrix[k][i][j];
						}
					}
					num[k] = max;
				}

				for (size_t k = 0; k < 2; k++) {
					for (size_t i = 0; i < 4; i++) {
						for (size_t j = 0; j < 4; j++) {
							m_matrix[i][j] = matrix[k][i][j] + num[k];
							print("{}\t", m_matrix[i][j]);
						}
						cout << endl;
					}
					cout << "=================" << endl;
				}
			}
			else {
				f = false;
				for (size_t k = 0; k < 2; k++) {
					for (size_t i = 0; i < 4; i++) {
						for (size_t j = 0; j < 4; j++) {
							cout << matrix[k][i][j] << '\t';
						}
						cout << endl;
					}
					cout << "==================" << endl;
				}
			}
			break;
		}
		case 's': {
			Make_matrix();
			break;
		}
		case 'q': {
			return 0;
		}
		default: {
			if (isdigit(input)) {
				int n = input - '0';
				if (num_bool != n)
					num_bool = n;
				else
					num_bool = 0;

				if (num_bool == 0) {
					for (size_t k = 0; k < 2; k++) {
						for (size_t i = 0; i < 4; i++) {
							for (size_t j = 0; j < 4; j++) {
								cout << matrix[k][i][j] << '\t';
							}
							cout << endl;
						}
						cout << "==================" << endl;
					}
				}
				else {
					if (n < 1 || n > 10)
						cout << "잘못된 입력입니다" << endl;
					else {
						for (size_t k = 0; k < 2; k++) {
							for (size_t i = 0; i < 4; i++) {
								for (size_t j = 0; j < 4; j++) {
									if (matrix[k][i][j] % n == 0) {
										print("{}\t", matrix[k][i][j]);
									}
									else
										print("\t");
								}
								cout << endl;
							}
							cout << "==================" << endl;
						}
					}
				}
			}
			else
				cout << "잘못된 입력입니다." << endl;
		}
		}
	}

}