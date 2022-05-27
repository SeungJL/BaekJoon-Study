#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

int dp[101][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1];
            } else if (j == 9) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            }
            dp[i][j] %= MOD;
        }
    }
    long long result = 0;
    for (int i = 0; i <= 9; i++) {
        result = (result + dp[N][i]) % MOD;
    }
    cout << result;
    return 0;
}