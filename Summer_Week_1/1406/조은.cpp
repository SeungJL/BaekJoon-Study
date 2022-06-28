// 실패 (시간초과)

#include <iostream>
#include <string>
#define MAX 101
using namespace std;

int main() {
	string str;
	cin >> str;
	int N = str.size(); // cursor
	// 만약 N=2로 이동하면, 커서가 세번째 글자의 '왼쪽'에 있다는 의미

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