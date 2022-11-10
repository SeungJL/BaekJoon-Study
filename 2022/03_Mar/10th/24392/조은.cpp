#include <iostream>
using namespace std;

int glass[1001][1001] = { 0 };
long long dp[1001][1001] = { 0 };

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			cin >> glass[i][j];
	
	for(int i=1; i<=M; i++)
		if(glass[N][i]) dp[N][i] = 1; // 맨 아랫줄 (초기값) 세팅

	for(int i=N-1; i>=1; i--) {
		for(int j=1; j<=M; j++) {
			if(glass[i][j]) {
				if(glass[i+1][j-1]) dp[i][j] += dp[i+1][j-1]%1000000007;
				if(glass[i+1][j]) dp[i][j] += dp[i+1][j]%1000000007;
				if(glass[i+1][j+1]) dp[i][j] += dp[i+1][j+1]%1000000007;
				dp[i][j] %= 1000000007;
			}
		}
	}

	long long ans = 0;
	for (int i = 1; i <= M; i++)
		ans += dp[1][i];

	cout << ans%1000000007;

	return 0;
}