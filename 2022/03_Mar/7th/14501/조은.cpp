#include <iostream>
#include <algorithm>
using namespace std;

int dp[16];
int T[16], P[16];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	for(int i=N; i>=1; i--) {
		if(i+T[i]-1 <= N) {
			dp[i] = max(P[i]+dp[i+T[i]], dp[i+1]);
		}
		else dp[i] = dp[i+1];
	}

	cout << dp[1];
	
	return 0;
}