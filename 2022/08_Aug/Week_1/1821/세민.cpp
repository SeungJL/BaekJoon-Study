#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int d[11][11];

int main(void)
{
	int N, F;
	cin >> N >> F;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		v[i] = i + 1;
	}
	d[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
		}
	}

	do {
		int now = 0;
		for (int i = 0; i < N; i++) {
			now += d[N][i + 1] * v[i];
		}
		if (now == F) {
			break;
		}
	} while (next_permutation(v.begin(), v.end()));
	for (auto a : v) {
		cout << a << " ";
	}
	return 0;
}