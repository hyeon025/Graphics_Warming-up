#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>

using namespace std;

//bool click_a{ false };
//bool click_c{ false };
//bool click_d{ false };
//bool click_e{ false };
//bool click_f{ false };
//bool click_g{ false };
//bool click_h{ false };
//int click_i{ 0 };
char click{};
int click_i{ 0 };
int jnum = 0;

int main() {

	string s;
	cout << "���� �̸� �Է�:";
	cin >> s;

	ifstream file(s);
	if (!file) {
		cout << "���� ����" << endl;
		return 1;
	}

	string line;
	string text;
	string save_text;

	while (getline(file, line)) {
		text += line + '\n';
	}

	file.close();
	///////////////////////////////////���� ���� ����

	char c;
	while (true) {
		cout << "��ɾ� �Է�:";
		cin >> c;
		switch (c) {
		case 'a': { //�빮�ڷ� (���)
			if(click != 'a'){
				click = 'a';
				save_text = text;

				transform(text.begin(), text.end(), text.begin(),
					[](char c) {return toupper(c); });
				cout << "==================" << endl;
				cout << text;
				cout << "==================" << endl;
			}
			else {
				click = ' ';
				text = save_text;
				cout << "==================" << endl;
				cout << text;
				cout << "==================" << endl;
			}
			break;
		}
		case 'b': { //�ܾ� ���� ���
			string ss{};
			cout << "==================" << endl;
			for (char c : text)
			{
				ss += c;
				if (c == '\n') {
					istringstream iss(ss);
					string word;
					int cnt = 0;
					while (iss >> word) {
						++cnt;
					}
					cout << ss;
					cout << "�ܾ� ����:" << cnt << endl;
					ss.clear();
				}
			}
			cout << "==================" << endl;
			break;
		}
		case 'c': {
			if (click != 'c') {
				click = 'c';
				save_text = text;
				int cnt = 0;
				istringstream is(text);
				string line;
				cout << "==================" << endl;
				while (getline(is, line)) {
					istringstream iss(line);
					string word;

					while (iss >> word) {
						if (!word.empty() && isupper(word[0])) {
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
							cout << word << " ";
							++cnt;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
						}
						else
							cout << word << " ";
					}
					cout << endl;
				}
				cout << "�빮�ڷ� �����ϴ� �ܾ� ����:" << cnt << endl;
				cout << "==================" << endl;
			}
			else {
				click = ' ';

				text = save_text;
				cout << "==================" << endl;
				cout << text;
				cout << "==================" << endl;
			}

			break;
		}
		case 'd': {
			if (click != 'd') {
				click = 'd';
				save_text = text;

				string sentence, out;
				
				for (char c : text) {
					if (c != '\n') {
						sentence += c;
					}
					else {
						reverse(sentence.begin(), sentence.end());
						out += sentence;
						out += '\n';
						sentence.clear();
					}
				}
				text = out;
				cout << "==================" << endl;
				cout << text << endl;
				cout << "==================" << endl;
			}
			else {
				click = ' ';
				text = save_text;

				cout << "==================" << endl;
				cout << text;
				cout << "==================" << endl;
			}

			break;
		}
		case 'e': {
			if (click != 'e') {
				click = 'e';
				save_text = text;

				string out;
				out.reserve(text.size());

				
				for (char c : text) {
					if (c == ' ') {
						out += '/';
					}
					else {
						out += c;
					}
				}
				text = out;
				cout << "==================" << endl;
				cout << text << endl;
				cout << "==================" << endl;

			}
			else {
				click = ' ';
				text = save_text;

				cout << "==================" << endl;
				cout << text;
				cout << "==================" << endl;

			}
			break;
		}
		case 'f': {
			if (click != 'f') {
				click = 'f';
				save_text = text;

				string out;
				out.reserve(text.size());
				string word;

				
				for (char c : text) {
					if (!(c == ' ' || c == '/') && c != '\n') {
						word += c;
					}
					else if (c == '\n') {
						reverse(word.begin(), word.end());
						out += word;
						out += '\n';
						word.clear();
					}
					else {
						reverse(word.begin(), word.end());

						out += word;
						out += c;
						word.clear();
					}
				}
				text = out;
				cout << "==================" << endl;
				cout << text << endl;
				cout << "==================" << endl;
			}
			else {
				click = ' ';
				text = save_text;
				cout << "==================" << endl;
				cout << text;
				cout << "==================" << endl;

			}
			break;
		}
		case 'g': {
			if (click != 'g') {
				click = 'g';
				char change;
				char new_ch;
				cout << "�ٲ� ����:";
				cin >> change;
				cout << "���ο� ����:";
				cin >> new_ch;

				string out;
				out.reserve(text.size());

				save_text = text;

				for (char c : text) {
					if (c == change) {
						out += new_ch;
					}
					else {
						out += c;
					}
				}

				text = out;
				cout << "==================" << endl;
				cout << text << endl;
				cout << "==================" << endl;

			}
			else {
				click = ' ';
				text = save_text;

				cout << "==================" << endl;
				cout << text << endl;
				cout << "==================" << endl;

			}
			break;
		}
		case 'h': {
			if (click != 'h') {
				click = 'h';

				save_text = text;

				string out;
				out.reserve(text.size());

				for (char c : text) {
					out += c;
					if (isdigit(c))
						out += '\n';
				}

				text = out;
				cout << "==================" << endl;
				cout << text << endl;
				cout << "==================" << endl;
			}
			else {
				click = ' ';
				text = save_text;
				cout << "==================" << endl;
				cout << text << endl;
				cout << "==================" << endl;
			}
			break;
		}
		case 'i': {
			if (click_i != 2) {
				click = 'i';
				
				
				if(click_i == 0)
					save_text = text;
				click_i++;

				vector<string> sentence;
				istringstream lines(text);
				string line;

				while (getline(lines, line)) {
					if (!line.empty())
						sentence.push_back(line);
				}

				auto alphacnt = [](const string& s) {
					int cnt = 0;
					for (char c : s) {
						if (isalpha(c))
							++cnt;
					}
					return cnt;
					};

				if (click_i == 1) { //��������
					sort(sentence.begin(), sentence.end(), [&](const string& a, const string& b) {
						return alphacnt(a) > alphacnt(b);
						});
				}
				else if (click_i == 2) { //��������
					sort(sentence.begin(), sentence.end(), [&](const string& a, const string& b) {
						return alphacnt(a) < alphacnt(b);
						});
				}

				string out;
				for (auto& a : sentence) {
					out += a + '\n';
				}
				text = out;
				cout << "==================" << endl;
				cout << text << endl;
				cout << "==================" << endl;
			}
			else {
				click = ' ';
				click_i = 0;
				text = save_text;
				cout << "==================" << endl;
				cout << text << endl;
				cout << "==================" << endl;
			}
			break;
		}
		case 'j': {
			char ch;
			string word;

			cin >> ch >> word;

			auto print_j = [&](const string& out, const string& word) {
				if (word.empty()) { //�ڿ� ������
					cout << out;
					return;
				}
				
				auto to_lower = [](string s) {
					for (char& c : s) c = (char)tolower((unsigned char)c);
					return s;
					};
				string low_out = to_lower(out);
				string low_word = to_lower(word);

				size_t pos = 0;
				while (true) {
					size_t hit = low_out.find(low_word, pos);
					if (hit == string::npos) {
						cout << out.substr(pos);
						break;
					}
					cout << out.substr(pos, hit - pos);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //��
					cout << out.substr(hit, word.size());
					++jnum;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //��
					pos = hit + word.size();
				}
				};
				auto print_j_c = [&](const string& s, const string& word) {
					auto to_lower = [](string t) {
						for (char& c : t) c = (char)tolower((unsigned char)c);
						return t;
						};
					string low_word = to_lower(word);

					auto flush_token = [&](const string& tok) {
						if (tok.empty()) return;

						bool upper = isupper((unsigned char)tok[0]); // ù ���� �빮�� ����(I'm -> 'I')

						if (word.empty()) {
							// �˻��� ������: �빮�� �����̸� �þ�, �ƴϸ� �⺻
							if (upper) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
								cout << tok;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
							}
							else {
								cout << tok;
							}
							return;
						}

						// �˻��� ������: ��ū ���ο��� �κ� ���ڿ�(��ҹ��� ����) ��Ī ������ ���,
						// �� �� ������ (�빮�� �����̸� �þ�) / �⺻��
						string low_tok = to_lower(tok);
						size_t p = 0;
						while (true) {
							size_t h = low_tok.find(low_word, p);
							if (h == string::npos) {
								if (p < low_tok.size()) {
									if (upper) {
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
										cout << tok.substr(p);
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
									}
									else {
										cout << tok.substr(p);
									}
								}
								break;
							}
							if (h > p) {
								if (upper) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
									cout << tok.substr(p, h - p);
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
								}
								else {
									cout << tok.substr(p, h - p);
								}
							}
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // ���(�˻���)
							cout << tok.substr(h, word.size());
							++jnum;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
							p = h + word.size();
						}
						};

					string tok;
					for (char chx : s) {
						if (isalnum((unsigned char)chx) || chx == '\'') {
							tok += chx;
						}
						else {
							flush_token(tok);
							tok.clear();
							cout << chx;
						}
					}
					flush_token(tok);
					};

			string out;
			switch (ch) {
			case 'a': {
				out = text;

				transform(out.begin(), out.end(), out.begin(),
					[](char c) {return toupper(c); });
				cout << "=======================" << endl;
				print_j(out, word);
				cout << "ã�� �ܾ� ����:" << jnum << "��" << endl;
				jnum = 0;
				cout << "=======================" << endl;
				break;
			}
			case 'b': {
				istringstream lines(text);
				string line;
				cout << "=======================" << endl;
				while (getline(lines, line)) {
					print_j(line, word);
					istringstream iss(line);
					string w; int cnt = 0;
					while (iss >> w) ++cnt;
					cout << "\n�ܾ� ����:" << cnt << endl;
				}
				cout << "ã�� �ܾ� ����:" << jnum << "��" << endl;
				jnum = 0;
				cout << "=======================" << endl;
				break;
			}
			case 'c': {
				cout << "=======================" << endl;
				print_j_c(text, word);
				cout << "ã�� �ܾ� ����:" << jnum << "��" << endl;
				jnum = 0;
				cout << "=======================" << endl;
				break;

				break;
			}
			case 'd': {

				string sentence;

				for (char c : text) {
					if (c != '\n') {
						sentence += c;
					}
					else {
						reverse(sentence.begin(), sentence.end());
						out += sentence;
						out += '\n';
						sentence.clear();
					}
				}
				if (!sentence.empty()) {
					reverse(sentence.begin(), sentence.end());
					out += sentence;
				}
				cout << "=======================" << endl;
				print_j(out, word);
				cout << "ã�� �ܾ� ����:" << jnum << "��" << endl;
				jnum = 0;
				cout << "=======================" << endl;
				break;
			}
			case 'e': {
				out.reserve(text.size());

				for (char c : text) {
					if (c == ' ') {
						out += '/';
					}
					else {
						out += c;
					}
				}
				cout << "=======================" << endl;
				print_j(out, word);
				cout << "ã�� �ܾ� ����:" << jnum << "��" << endl;
				jnum = 0;
				cout << "=======================" << endl;
				break;
			}
			case 'f': {
				out.reserve(text.size());
				string word_jf;

				for (char c : text) {
					if (!(c == ' ' || c == '/') && c != '\n') {
						word_jf += c;
					}
					else if (c == '\n') {
						reverse(word_jf.begin(), word_jf.end());
						out += word_jf;
						out += '\n';
						word_jf.clear();
					}
					else {
						reverse(word_jf.begin(), word_jf.end());

						out += word_jf;
						out += c;
						word_jf.clear();
					}
				}
				if (!word_jf.empty()) {
					reverse(word_jf.begin(), word_jf.end());
					out += word_jf;
				}

				cout << "=======================" << endl;
				print_j(out, word);
				cout << "ã�� �ܾ� ����:" << jnum << "��" << endl;
				jnum = 0;
				cout << "=======================" << endl;
				break;
			}
			case 'g': {
				char change;
				char new_ch;
				cout << "�ٲ� ����:";
				cin >> change;
				cout << "���ο� ����:";
				cin >> new_ch;

				out.reserve(text.size());

				save_text = text;

				for (char c : text) {
					if (c == change) {
						out += new_ch;
					}
					else {
						out += c;
					}
				}
				cout << "=======================" << endl;
				print_j(out, word);
				cout << "ã�� �ܾ� ����:" << jnum << "��" << endl;
				jnum = 0;
				cout << "=======================" << endl;
				break;
			}
			case 'h': {
				out.reserve(text.size());

				for (char c : text) {
					out += c;
					if (isdigit(c))
						out += '\n';
				}
				cout << "=======================" << endl;
				print_j(out, word);
				cout << "ã�� �ܾ� ����:" << jnum << "��" << endl;
				jnum = 0;
				cout << "=======================" << endl;
				break;
			}
			case 'i': {

				vector<string> sentence;
				istringstream lines(text);
				string line;

				while (getline(lines, line)) {
					if (!line.empty())
						sentence.push_back(line);
				}

				auto alphacnt = [](const string& s) {
					int cnt = 0;
					for (char c : s) {
						if (isalpha(c))
							++cnt;
					}
					return cnt;
					};

				//��������
				sort(sentence.begin(), sentence.end(), [&](const string& a, const string& b) {
					return alphacnt(a) > alphacnt(b);
					});
				
				for (auto& a : sentence) {
					out += a + '\n';
				}
				cout << "=======================" << endl;
				print_j(out, word);
				cout << "ã�� �ܾ� ����:" << jnum << "��" << endl;
				jnum = 0;
				cout << "=======================" << endl;
				break;

			}
			default: {
				out = text;
				cout << "=======================" << endl;
				print_j(out, word);
				cout << "ã�� �ܾ� ����:" << jnum << "��" << endl;
				jnum = 0;
				cout << "=======================" << endl;
				break;
			}
			}
			
			break;
		}
		case 'q': {
			return 0;
		}
		}
	}

}