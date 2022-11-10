#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <cmath>

using namespace std;
string str[51];

bool compare(string a, string b) {
	if (a.size() == b.size()) {
		int n = 0; int m = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] < 58) {
				n += a[i] - 48;
			}
		}
		for (int i = 0; i < b.size(); i++) {
			if (b[i] < 58) {
				m += b[i] - 48;
			}
		}
		if (m == n) {
			return a < b;
		}
		else { return n < m; }
	}
	else { return a.size() < b.size(); }
}

int main() {
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
	sort(str, str + N, compare);
	int i = 0;
	while (N--) {
		cout << str[i] << endl;
		i++;
	}
}