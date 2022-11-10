#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int combination(int n, int r) {
	long long res = 1;
	int _r = r;
	while (_r--) {
		res *= n--;
	}
	while (r) {
		res /= r--;
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("input.txt", "rt", stdin);
	int T, N, M;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		int n = max(N, M);
		int r = min(N, M);
		if (r < (n - r)) cout << combination(n, r) << '\n';
		else cout << combination(n, n - r) << '\n';
	}

	return 0;
}
