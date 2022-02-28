#include <bits/stdc++.h>

using namespace std;

int dp[50001];

int main() {
    int n;
    cin >> n;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int min = INT_MAX;
        if ((int) sqrt(i) * (int) sqrt(i) == i) {
            //printf("제곱!!\n");
            min = 1;
        } else {
            for (int j = 1; j * j < i; j++) {
                int tmp = dp[j * j] + dp[i - j * j];
                if (tmp < min) min = tmp;
            }
            //   printf("min = %d\n",min);
        }
        dp[i] = min;
        // printf("dp[%d]=%d\n", i, dp[i]);
    }
    cout << dp[n];

    return 0;
}
/*
 * 1 = 1
 * 2 = 1+1
 * 3 = 1+1+1
 * 4 = 4
 * 5 = 1+4
 * 6 = 1+1+4
 * 7 = 1+1+1+4
 * 8 = 4+4
 * 9 = 9
 * 10 = 1+9
 * 11 = 1+1+9
 * 12 = 4+4+4
 * 13 = 4+9
 * 14 = 1+4+9
 * 15 = 1+1+4+9
 * 16 = 16
 *
 *
 * '1' 2 3 1 2 3 4 2 1 2 3 3 2 3 4 1
 */