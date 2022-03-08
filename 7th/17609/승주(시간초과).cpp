#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

bool reverse(string str) {
	string a = str.substr(0, (int)str.size() / 2);
	string b = str.substr(ceil((float)str.size() / (float)2));
	reverse(b.begin(), b.end());
	return a == b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	string str;
	for (int i = 0; i < T; i++) {
		int flag = 0;
		cin >> str;
		if (reverse(str) == 1) {
			cout << 0 << '\n';
			continue;
		}
		else {

			for (int j = 0; j < str.size(); j++) {
				string str2 = str;
				str2.replace(j, 1, "");
				if (str2[0] != str2[str2.size() - 1] || str2[1] != str2[str2.size() - 2]) {
					continue;
				}

				if (reverse(str2) == 1) {
					cout << 1 << '\n';
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0)cout << 2 << '\n';
	}
}
