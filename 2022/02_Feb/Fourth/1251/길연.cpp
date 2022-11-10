// 백준 1251번 
// 2022년 2월 1일

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string word;
	cin >> word;

	string a, b, c;  // 3등분
	string ans = "";

	for (int i = 1; i < word.length() - 2; ++i) {
		for (int j = 1; j < word.length() - i; ++j) {
			
			// substr(start, len)
			a = word.substr(0, i);
			b = word.substr(i, j);
			c = word.substr(i+j);

			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			reverse(c.begin(), c.end());

			if (ans == "")
				ans = a + b + c;
			else if ((a + b + c) < ans) // 사전순
				ans = a + b + c;
		}
	}

	cout << ans << endl;

	return 0;
}
