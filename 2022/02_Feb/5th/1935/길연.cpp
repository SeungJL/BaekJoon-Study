// 백준 1935번 후위 표기식2

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;
double operate(double a, double b, char op) {
	switch (op) {
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a * b;
		break;
	case '/':
		return a / b;
		break;
	}
}

int main() {

	int num;
	string exp;
	cin >> num >> exp;

	vector<int> v(num);
	stack<double> st; // 후위표기식은 스택기반

	for (int i = 0; i < num; i++)
		cin >> v[i];

	for (int i = 0; i < exp.length(); i++) {
		if (exp[i] >= 'A' && exp[i] <= 'Z') {
			st.push(v[exp[i] - 'A']);
		}
		else {
			double b = st.top();
			st.pop();
			double a = st.top();
			st.pop();
			st.push(operate(a, b, exp[i]));
			}
		}

	double ans = st.top();
	cout.precision(2);
	cout << fixed;
	cout << ans << endl;

	return 0;
}
