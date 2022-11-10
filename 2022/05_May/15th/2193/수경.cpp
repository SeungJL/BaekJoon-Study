#include <bits/stdc++.h>

using namespace std;

long long dp[91];

int main() {
    dp[1] = 1;
    dp[2] = 1;
    long long N;
    cin >> N;
    for (int i = 3; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2];

    cout << dp[N];

    return 0;
}
/*
 * N = 1
 * 1
 * 1
 *
 * N = 2
 * 10
 * 1
 *
 * N = 3
 * 101
 * 100
 * 2
 *
 * N = 4
 * 1000
 * 1001
 * 1010
 * 3
 *
 * N = 5
 * 10000
 * 10001
 * 10010
 * 10100
 * 10101
 * 5
 */