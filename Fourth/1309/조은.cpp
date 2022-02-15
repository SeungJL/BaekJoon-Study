#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX 100001
#define MOD 9901
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "rt", stdin);
	int N;
	cin >> N;
	int dp[MAX];
	/*
	3
	1+4+2 =7
	1+6+8+2 =17
	...
	*/
	dp[1] = 3; dp[2] = 7;
	for (int i = 3; i <= N; i++) {
		dp[i] = (2 * dp[i - 1] + dp[i - 2]) % MOD;
	}
	cout << dp[N];

	return 0;
}