#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "rt", stdin);
	string s;
	cin >> s;
	int len = s.size();
	string s1, s2, s3, ans = "zzzzzzzzzzzzzzzzzzzzz";
	for (int i = 1; i < len - 2; i++) {
		for (int j = 1; j < len - i; j++) {
			s1 = s.substr(0, i);
			s2 = s.substr(i, j);
			s3 = s.substr(i + j);
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			reverse(s3.begin(), s3.end());
			string temp = s1 + s2 + s3;
			if (temp < ans) ans = temp;
		}
	}
	cout << ans;

	return 0;
}
