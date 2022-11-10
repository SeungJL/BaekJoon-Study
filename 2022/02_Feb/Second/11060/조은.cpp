#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1000];

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for(int i=0; i<N; i++)
		cin >> v[i];

	fill(dp, dp+1000, 99999999);
	dp[0] = 0;
	for(int i=1; i<N; i++) {
		for(int j=0; j<i; j++) {
			if(v[j] < (i-j)) continue;
			dp[i] = min(dp[j]+1, dp[i]);
		}
	}
	if(dp[N-1] != 99999999) cout << dp[N-1];
	else cout << -1;

	return 0;
}