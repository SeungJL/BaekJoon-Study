#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int getTotal(const string &s) {
	int total = 0;
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') total += (s[i] - '0');
	}
	return total;
}

bool cmp(const string &s1, const string &s2) {
	int len1 = s1.size(), len2 = s2.size();
	if (len1 == len2) {
		int total1 = getTotal(s1);
		int total2 = getTotal(s2);
		if (total1 == total2) return s1 < s2;
		else return total1 < total2;
	}
	else return len1 < len2;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	int N;  cin >> N;
	vector<string> v(N);
	for(int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << v[i] << '\n';
	}

	return 0;
}
