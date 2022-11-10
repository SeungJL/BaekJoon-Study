#include <iostream>

using namespace std;

int N;
int dp[30];

int Fill(int n)
{
	dp[0] = 1;
	dp[1] = 3;
	if (n % 2 != 0) {
		return 0;
	}
	for (int i = 2; i <= N / 2; i++) {
		dp[i] = dp[i - 1] * 4 - dp[i - 2];
	}

	return dp[N / 2];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	cout << Fill(N) << '\n';

	return 0;
}