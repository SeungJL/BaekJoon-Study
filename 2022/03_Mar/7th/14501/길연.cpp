// 백준 14501번 퇴사
// 2022년 03월 06일

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int day[16];
int money[16];
int dp[16] = { 0, };

// 그 날의 최대이익 구하는건 역순으로. 지난번 주식문제랑 비슷하게 가자
int main() {
	
	int n;
	cin >> n;
	for (int i = 1; i < n+1; i++) {
		cin >> day[i] >> money[i];
	}

	for (int i = n; i > 0; i--) {
		if (day[i] + i > n + 1 ) {  // 7일차 + 1 (o), 6일차 + 2 (x)
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + 1], dp[i + day[i]] + money[i] );
		}
	}

	cout << dp[1] << endl;

	return 0;
}
