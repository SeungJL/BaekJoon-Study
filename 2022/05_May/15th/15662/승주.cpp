#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void left(vector <int>& V) {
	V.push_back(V.front());
	V.erase(V.begin());
}

void right(vector <int>& V) {
	V.insert(V.begin(), V.back());
	V.pop_back();
}

void check(vector <int>& V, int h) {
	if (h == -1) { return left(V); }
	else { return right(V); }
}

int main() {
	int T, K;
	int x, a, b;
	cin >> T;
	vector <vector <int>> V(T);
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &x);
			V[i].push_back(x);
		}
	}
	cin >> K;
	int L, R;
	int Two, Six, Two_T, Six_T, h_T;
	int h;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		if (b == -1) { h = -1; }
		else { h = 1; }
		L = 0; R = 0;
		Six = V[a - 1][6];
		Two = V[a - 1][2];
		check(V[a - 1], h);
		h = -h;
		Six_T = Six;
		Two_T = Two;
		h_T = h;
		while (1) {
			L++;
			if (a - 1 - L >= 0) {
				Two = V[a - 1 - L][2];
				if (Six != Two) {
					Six = V[a - 1 - L][6];
					check(V[a - 1 - L], h);
					h = -h;
				}
				else { break; }
			}
			else { break; }
		}

		Six = Six_T;
		Two = Two_T;
		h = h_T;
		while (1) {
			R++;
			if (a - 1 + R < T) {
				Six = V[a - 1 + R][6];
				if (Two != Six) {
					Two = V[a - 1 + R][2];
					check(V[a - 1 + R], h);
					h = -h;
				}
				else { break; }
			}
			else { break; }
		}

	}
	int cnt = 0;
	for (int i = 0; i < V.size(); i++) {
		if (V[i][0] == 1) { cnt++; }
	}
	cout << cnt;

}