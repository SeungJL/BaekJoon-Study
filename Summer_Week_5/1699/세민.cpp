#include <iostream>

using namespace std;

int dp[100001] = {};
int Min(int A, int B) { return A < B ? A : B; }
int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		dp[i] = i;
		for (int j = 1; j*j <= i; j++) {
			dp[i] = Min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n];

	return 0;
}