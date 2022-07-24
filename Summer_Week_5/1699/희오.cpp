// BOJ 1699

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	// freopen("input.txt", "rt", stdin);

	int N;
	cin >> N;

	vector<int> dp(N+1, 0);
	int sqrt_n = 1;

	for (int i=1; i<=N; i++) {
		if (sqrt_n * sqrt_n == i) {
			dp[i] = 1;
			sqrt_n++;
		}
		else {
			int min = 2147000000;
			for (int s = sqrt_n-1; s > 0; s--) {
				int tmp = 1 + dp[i - (s * s)];
				if (tmp < min) min = tmp;
			}
			dp[i] = min;
		}
	}
	cout << dp[N] << "\n";
}