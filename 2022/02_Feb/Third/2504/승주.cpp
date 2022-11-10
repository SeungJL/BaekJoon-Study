#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	string str;
	cin >> str;

	stack <string>s;
	stack <string> s2;


	while (1) {
		int h = 0;
		if (str.find("()") != string::npos) {
			str.replace(str.find("()"), 2, "2");
			h = 1;
		}
		if (str.find("[]") != string::npos) {
			str.replace(str.find("[]"), 2, "3");
			h = 1;
		}
		if (h == 0) { break; }
	}

	int x;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ')') {
			if (s2.empty() == 1) {
				cout << 0;
				return 0;
			}
			if (s2.top() == "(") {
				s2.pop();
			}
			else { cout << 0; return 0; }
			x = stoi(s.top());
			s.pop();
			while (1) {
				if (s.top() != "(" && s.top() != "[") {
					int k = stoi(s.top());
					s.pop();
					x += k;
				}
				else { break; }
			}
			if (s.top() == "(") {
				s.pop();
				x *= 2;
				s.push(to_string(x));
			}
		}
		else if (str[i] == ']') {
			if (s2.empty() == 1) {
				cout << 0;
				return 0;
			}
			if (s2.top() == "[") {
				s2.pop();
			}
			else { cout << 0; return 0; }
			x = stoi(s.top());
			s.pop();
			while (1) {
				if (s.top() != "(" && s.top() != "[") {
					int k = stoi(s.top());
					s.pop();
					x += k;
				}
				else { break; }
			}
			if (s.top() == "[") {
				s.pop();
				x *= 3;
				s.push(to_string(x));
			}
		}
		else {
			string a = "";
			a += str[i];
			s.push(a);
			if (a == "(" || a == "[") {
				s2.push(a);
			}
		}

	}
	if (s2.empty() != 1) {
		cout << 0;
		return 0;
	}
	int sum = 0;
	while (s.empty() != 1) {
		sum += stoi(s.top());
		s.pop();
	}
	cout << sum;
}