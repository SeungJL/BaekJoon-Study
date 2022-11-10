#include <bits/stdc++.h>

#define MOD 15746

using namespace std;
int dp[1000001];

int main() {
    int N;
    scanf("%d", &N);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    }
    printf("%d\n", dp[N]);
    return 0;
}
/*
 * N = 1
 * 1
 * 1가지
 *
 * N = 2
 * 11
 * 00
 * 2가지
 *
 * N = 3
 * 111
 * 100
 * 001
 * 3가지
 *
 * N = 4
 * 1111
 * 1100
 * 1001
 * 0011
 * 0000
 * 5가지
 *
 * N = 5
 * 11111
 * 11100
 * 11001
 * 10011
 * 00111
 * 10000
 * 00100
 * 00001
 * 8가지
 */