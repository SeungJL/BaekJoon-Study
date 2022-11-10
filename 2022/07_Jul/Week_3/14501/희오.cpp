// BOJ 14501 퇴사

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    int N;
    cin >> N;

    vector<int> dp(N+1, 0);
    int max = 0;
    for(int i=1; i<=N; i++) {
        int T, P;
        cin >> T >> P;
        if (i + T - 1 <= N) {
            if (dp[i-1] + P > dp[i+T-1])
                dp[i+T-1] = dp[i-1] + P;
        }
        if (!dp[i])
            dp[i] = dp[i-1];
        if (dp[i] > max)
            max = dp[i];
        else
            dp[i] = max;
    }

    cout << dp[N] << "\n";
}