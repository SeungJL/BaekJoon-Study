#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int T, a, b;
	string X;

	vector <string> V;
	vector <int> S;
	vector <int> B;
	int flag;
	int cnt = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> X >> a >> b;
		V.push_back(X);
		S.push_back(a);
		B.push_back(b);
	}
	for (int i = 100; i <= 999; i++) {
		flag = 0;
		string str = to_string(i);
		for (int z = 0; z < 3; z++) {
			if (str[z] == '0') { flag = 1; }
		}
		if (flag == 1) { continue; }
		if (str[0] == str[1] || str[1] == str[2] || str[0] == str[2]) {
			continue;
		}
		for (int z = 0; z < V.size(); z++) {
			int strike = 0;
			int ball = 0;
			string str2 = V[z];
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (str[j] == str2[k]) {
						if (j == k) {
							strike++;
						}
						else { ball++; }
					}
				}
			}
			if (strike == S[z] && ball == B[z]) {
			}
			else {
				break;
			}
			if (z == V.size() - 1) {
				cnt++;
			}
		}
	}
	cout << cnt;
}