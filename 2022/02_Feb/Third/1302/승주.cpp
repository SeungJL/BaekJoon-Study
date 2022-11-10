#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
	int N;
	string list[1001];
	string ans;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N);
	int Max = 0;
	int cnt = 1;
	if (N == 1) {
		cout << list[0];
		return 0;
	}
	for (int i = 0; i < N - 1; i++) {
		if (list[i] == list[i + 1]) {
			cnt++;
		}
		else {
			if (cnt > Max) {
				Max = cnt;
				ans = list[i];
			}
			cnt = 1;
		}
		if (i == N - 2) {
			if (cnt > Max) {
				Max = cnt;
				ans = list[i];
			}
		}
	}
	cout << ans;

}