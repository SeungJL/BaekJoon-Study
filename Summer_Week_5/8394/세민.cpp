#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int dp[10000001] = {};
	dp[1] = 1, dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
	}

	cout << dp[n];

	return 0;
}