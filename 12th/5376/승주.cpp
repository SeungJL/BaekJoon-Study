#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


long long str_sum(string s) {
	long long s_sum = 0;
	for (int i = 0; i < s.size(); i++) {
		s_sum *= 10;
		s_sum += (s[i] - '0');
	}
	return s_sum;
}

long long GCD(long long x, long long y) {
	if (y == 0) { return x; }
	long long temp = y;
	y = x % y;
	return GCD(temp, y);
}

int main() {
	int T;
	long long x, y; // ����,�и�
	string str, str1, str2;
	cin >> T;

	while (T--) {
		cin >> str;
		int index = str.find('(');
		if (index == string::npos) {
			str1 = str.substr(2);
			str2 = "";
		}
		else {
			str1 = str.substr(2, index - 2);
			str2 = str.substr(index + 1);
			str2.pop_back();
		}

		if (str2.size() == 0) {
			x = stoi(str1);
			y = pow(10, str1.size());
		}
		else {
			long long temp = 0;
			for (int i = 0; i < str1.size() + str2.size(); i++) {
				if (i < str2.size()) {
					temp *= 10;
					temp += 9;
				}
				else {
					temp *= 10;
				}
			}
			y = temp;
			x = str_sum(str1 + str2) - str_sum(str1);
		}
		long long z = GCD(x, y);
		x /= z;
		y /= z;
		cout << x << '/' << y << endl;
	}
}