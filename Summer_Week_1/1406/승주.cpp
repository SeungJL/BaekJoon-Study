#include <iostream>
#include <deque>

using namespace std;

int main() {

	string str;
	deque <char> D;
	int M;
	char Input, Input2;
	int pos;

	cin >> str;
	pos = str.size();
	for (int i = 0; i < str.size(); i++) {
		D.push_back(str[i]);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> Input;
		switch (Input) {
		case 'L':
			if (pos != 0) {
				D.push_front(D.back());
				D.pop_back();
				pos--;
			}
			break;
		case 'D':
			if (pos != D.size()) {
				D.push_back(D.front());
				D.pop_front();
				pos++;
			}
			break;
		case 'B':
			if (pos != 0) {
				D.pop_back();
				pos--;
			}
			break;
		case 'P':
			cin >> Input2;
			D.push_back(Input2);
			pos++;
			break;
		}
	}
	while (pos--) {
		D.push_front(D.back());
		D.pop_back();
	}
	while (D.size()) {
		cout << D.front();
		D.pop_front();
	}
}