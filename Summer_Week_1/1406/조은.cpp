// ���� (�ð��ʰ�)

#include <iostream>
#include <string>
#define MAX 101
using namespace std;

int main() {
	string str;
	cin >> str;
	int N = str.size(); // cursor
	// ���� N=2�� �̵��ϸ�, Ŀ���� ����° ������ '����'�� �ִٴ� �ǹ�

	int M;
	cin >> M;

	char c, ch;
	for(int i=0; i<M; i++) {
		cin >> c;
		switch (c) {
		case 'L':
			if(N > 0) N--;
			break;
		case 'D':
			if(N < str.size()) N++;
			break;
		case 'B':
			if(N > 0) {
				str.erase(N-1, 1);
				N--;
			}
			break;
		case 'P':
			cin >> ch;
			string s = "";
			s += ch;
			str.insert(N, s);
			N++;
			break;
		}
	}

	cout << str;

	return 0;
}