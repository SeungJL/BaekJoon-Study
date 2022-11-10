#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[10001] = { 0 };
int dp[10001]; // dp[n]: n번째 포도주까지 최대로 마실 수 있는 양

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for(int i=0; i<=n; i++) {
		if(i<=2) { // 초기값 설정
			for(int j=0; j<=i; j++)
				dp[i] += a[j];
		}
		else { // 점화식
			dp[i] = dp[i-3] + a[i-1] + a[i];
			dp[i] = max(dp[i], dp[i-2] + a[i]);
			dp[i] = max(dp[i], dp[i-1]);
		}
	}

	cout << dp[n];
	
	return 0;
}
