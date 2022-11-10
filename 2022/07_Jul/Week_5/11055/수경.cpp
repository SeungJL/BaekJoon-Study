#include <bits/stdc++.h>

using namespace std;

int N;
int A[1001];
int dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int max_dp;
    for (int i = 1; i <= N; i++) {
        dp[i] = A[i];   // dp[i]의 최솟값: A[i]
        for (int j = 1; j <= i; j++) {
            if (A[i] > A[j] && dp[i] < dp[j] + A[i]) dp[i] = dp[j] + A[i];
        }
        max_dp = max(max_dp, dp[i]);
    }

    cout << max_dp;

    return 0;
}