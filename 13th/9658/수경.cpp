#include <bits/stdc++.h>

using namespace std;
int dp[1001];
int main() {
    int N;
    scanf("%d", &N);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    dp[4] = 1;
    for (int i = 5; i <= N; i++) {
        if (dp[i - 1] == 1 && dp[i - 3] == 1 && dp[i - 4] == 1) dp[i] = 0;
        else dp[i] = 1;
    }
    if(dp[N] == 1) printf("SK\n");
    else printf("CY\n");
    return 0;
}
/*
 * 상근이 기준 상근이가 이기면 1 패배하면 0
 * N = 1: 0
 * s 1
 * c
 *
 * N = 2: 1
 * s 1
 * c 1
 *
 * N = 3: 0
 * s 1 1
 * c 1
 *
 * N = 4: 1
 * s 3
 * c 1
 *
 * N = 5: 1
 * s 4
 * c 1
 *
 * N = 6: 1
 * s 3 1
 * c 1 1
 *
 * N = 7: 1
 * s 4 1
 * c 1 1
 *

 *
 */