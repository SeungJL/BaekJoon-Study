#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <cmath>

using namespace std;

int main() {
	int T, N;
	vector <int> V;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int p = 0;
		int Max = 0;
		long long sum = 0;
		int cnt = 0;
		long long ans = 0;
		V.clear();
		cin >> N;
		int x;
		for (int i = 0; i < N; i++) {
			cin >> x;
			if (x > Max) {
				Max = x;
			}
			V.push_back(x);
		}
		for (int i = 0; i < N; i++) {

			cnt++;
			if (V[i] == Max) {
				if (cnt == 1) {
					for (int j = i + 1; j < N; j++) {
						if (V[j] == Max) { p = 1; break; }
					}
					if (p == 0) { break; }

				}
				ans += (long long)Max * ((long long)cnt - 1) - sum;
				sum = 0;
				cnt = 0;
				Max = 0;
				for (int j = i + 1; j < N; j++) {
					if (V[j] > Max) {
						Max = V[j];
					}
				}
				sum -= (long long)V[i];
			}
			sum += (long long)V[i];
		}
		cout << ans << endl;
	}
}