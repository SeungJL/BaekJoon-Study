// 1535
// https://hio9105.tistory.com/entry/BOJ-1535-%EC%95%88%EB%85%95-bruteforcing-dp-knapsack

#include <iostream>

using namespace std;

#define MAX_L 100

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	int N;
	int L[21] = {}, J[21] = {};

	/* input */
	cin >> N;
	for (int i=1; i<=N; i++) cin >> L[i];
	for (int i=1; i<=N; i++) cin >> J[i];

	/* solve */
	int dp[21][MAX_L] = {};
	// dp[i][j] = i 번째 사람에게까지 인사할 수 있고, 체력이 j만큼 있다고 했을 때 얻을 수 있는 최대 기쁨
    
	for (int i=1; i<=N; i++) {
		for (int j=1; j<MAX_L; j++) {
			dp[i][j] = dp[i-1][j];
			if (j - L[i] >= 0)
				dp[i][j] = max(dp[i-1][j], dp[i-1][j - L[i]] + J[i]);
		}
	}

	/* print answer */
	cout << dp[N][MAX_L - 1] << "\n";
}
