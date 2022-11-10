#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long dp[81];

int main() {
	//freopen("input.txt", "rt", stdin);
	int N;
	cin >> N;
	
	dp[1] = 1; dp[2] = 1;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	long long perimeter = 2 * (2 * dp[N] + dp[N - 1]);
	cout << perimeter << endl;

	return 0;
}
