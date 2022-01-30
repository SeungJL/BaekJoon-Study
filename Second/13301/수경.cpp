#include <bits/stdc++.h>

using namespace std;

//dynamic programming
long long dp[81];

int main() {
    int N;
    scanf("%d", &N);

    dp[1] = 4;
    dp[2] = 6;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    printf("%d\n", dp[N]);


    return 0;
}