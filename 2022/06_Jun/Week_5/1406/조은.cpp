#include <iostream>
#include <stack>
using namespace std;

int main() {
	string str;
	cin >> str;
	int N = str.length();

	stack<char> left, right; // 커서 기준 왼쪽, 오른쪽
	for (int i = 0; i < N; i++)
		left.push(str[i]);

	int M;
	cin >> M;

	char c, ch;
	for(int i=0; i<M; i++) {
		cin >> c;
		switch (c) {
		case 'L':
			if(left.empty()) continue;
			right.push(left.top());
			left.pop();
			break;
		case 'D':
			if(right.empty()) continue;
			left.push(right.top());
			right.pop();
			break;
		case 'B':
			if(left.empty()) continue;
			left.pop();
			break;
		case 'P':
			cin >> ch;
			left.push(ch);
			break;
		}
	}

	while(!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}

	return 0;
}