#include <bits/stdc++.h>

using namespace std;

int dp[100001];

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= sqrt(N); i++) {
        dp[i * i] = 1;
    }
    for (int i = 2; i <= N; i++) {
        if (dp[i] == 1) continue;
        dp[i] = dp[i - 1] + 1;
        for (int j = 0; j <= sqrt(i); j++) {
            if (dp[i - j * j] < dp[i] - 1) dp[i] = dp[i - j * j] + 1;
        }
    }
    cout << dp[N];
    return 0;
}