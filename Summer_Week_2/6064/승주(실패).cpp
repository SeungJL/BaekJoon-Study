#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int M, N, x, y;
	int a, b, T;
	int cnt = 1;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> x >> y;
		a = 1; b = 1;
		while (1) {
			if (a == x && b == y) { cout << cnt; break; }
			if (a == M) { a = 0; }
			if (b == N) { b = 0; }
			a++;
			b++;
			cnt++;
		}
	}
}