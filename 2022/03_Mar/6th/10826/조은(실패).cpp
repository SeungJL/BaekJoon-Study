#include <iostream>
using namespace std;

string dp[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	dp[0]=0; dp[1]=1;
	for(int i=2; i<=n; i++) {
		dp[i] = dp[i-1]+dp[i-2];
	}
	cout << dp[n];

	return 0;
}