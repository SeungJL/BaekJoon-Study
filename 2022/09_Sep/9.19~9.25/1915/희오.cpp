#include <iostream>

using namespace std;

int get_min(int a, int b, int c) {
	int res = a;
	if (b < res) res = b;
	if (c < res) res = c;

	return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "rt", stdin);

	int n, m, max_size = 0;
	int dp[1001][1001] = {};

	cin >> n >> m;
	char input;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> input;
			dp[i][j] = input - '0';
			if (dp[i][j]) {
				dp[i][j] += get_min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
			}
			if (dp[i][j] > max_size) max_size = dp[i][j];
		}
	}

	cout << max_size * max_size << "\n";

}