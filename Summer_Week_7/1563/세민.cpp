#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
constexpr int MOD = 1'000'000;

using namespace std;

int dp[1001][2][3];
int N;

int f(int date, int late, int absence) {
	if (late == 2) return 0;
	else if (absence == 3) return 0;

	if (date == N) return 1;

	int &ret = dp[date][late][absence];
	if (ret != -1) return ret;
	ret = 0;

	ret += f(date + 1, late + 1, 0) + f(date + 1, late, absence + 1) + f(date + 1, late, 0);

	return ret % MOD;
}


int main() {
	// freopen("input.txt", "r", stdin);
	cin >> N;

	memset(dp, -1, sizeof(dp));

	cout << f(0, 0, 0);
	return 0;
}

