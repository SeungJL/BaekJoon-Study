#include <bits/stdc++.h>

using namespace std;

int dp[10001];
int grape[10001];

/*
 * 1. (1, 2) dp[i-1]
 * 2. (1, 3) dp[i-2]+grape[i]
 * 3. (2, 3) dp[i-3]+grape[i-1]+grape[i]
 */
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &grape[i]);
    }
    dp[1] = grape[1];
    dp[2] = grape[1] + grape[2];
    for (int i = 3; i <= N; i++) {
        dp[i] = max(dp[i-1], max(dp[i-2]+grape[i], dp[i-3]+grape[i-1]+grape[i]));
    }
    printf("%d", dp[N]);

    return 0;
}