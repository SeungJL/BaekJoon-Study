#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "rt", stdin);
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		if (K == 1) {
			cnt++;
			break;
		}
		if (cnt += K / v[i]) {
			K %= v[i];
		}
	}
	cout << cnt;

	return 0;
}