#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	stack <double> s;
	int list2[27];
	int N;
	string str;

	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++) {
		cin >> list2[i];
	}

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 65) {
			s.push(list2[str[i] - 65]);
		}
		else {
			double a = s.top();
			s.pop();
			double b = s.top();
			s.pop();
			switch (str[i]) {
			case '*':
				s.push(b * a);
				break;
			case '/':
				s.push(b / a);
				break;
			case '+':
				s.push(b + a);
				break;
			case '-':
				s.push(b - a);
				break;
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << s.top();
}