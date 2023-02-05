#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	int N;
	long long dp[101][10] = {};
	
	cin >> N;
	for (int i=1; i<10; i++) 
		dp[1][i] = 1;
	for (int i=2; i<=N; i++) {
		dp[i][0] = (dp[i-1][1]) % 1000000000;
		for (int j=1; j<9; j++)
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
		dp[i][9] = (dp[i-1][8]) % 1000000000;
	}

	long long answer = 0;
	for (auto e : dp[N])
		answer = (answer + e) % 1000000000;
	cout << answer << "\n";

}