#include <bits/stdc++.h>

using namespace std;

/*
 * 1 1 2 3 5 8 ...
 *
 * 1 -> 가로:1 세로:1 -> 4
 * 2 -> 가로:1 세로:1 -> 6
 * 3 -> 가로:1+2 세로:1 -> 10
 * 4 -> 가로:1+2 세로:1 -> 16
 * 5 -> 가로:1+2+5 세로:1 -> 26
 */



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