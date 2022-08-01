#include <iostream>
#include <algorithm>

using namespace std;

int T[51];

int main(void)
{
	int N, C, W;
	cin >> N >> C >> W;
	for (int i = 0; i < N; i++) {
		cin >> T[i];
	}

	sort(T, T + N);
	long long ans = INT_LEAST64_MIN;

	for (int i = 1; i <= T[N - 1]; i++) {
		long long sum = 0;
		for (int j = 0; j < N; j++) {
			int cut = 0;
			if (T[j] >= i) {
				if (T[j] % i == 0) {
					cut = T[j] / i - 1;
				}
				else {
					cut = T[j] / i;
				}

				if (W * i * (T[j] / i) - cut * C > 0) {
					sum += W * i * (T[j] / i) - cut * C;
				}
			}
		}
		ans = max(ans, sum);
	}
	cout << ans;

	return 0;
}