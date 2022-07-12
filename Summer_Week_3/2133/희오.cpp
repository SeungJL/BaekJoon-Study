#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    // freopen("input.txt", "rt", stdin);

    int N;
    cin >> N;

    // N이 홀수일 경우, 타일로 벽을 채울 수 없음
    if (N % 2 == 1) {
        cout << "0\n";
        return 0;
    }

    // dp[n/2] = DP(n)
    vector<int> dp(N/2 + 1, 0);
    dp[0] = 0;
    dp[1] = 3; // DP(2)에 해당

    for (int i=2; i<=N/2; i++) {
        dp[i] += dp[i-1] * 3 + 2;
        for (int k=i-2; k>0; k--) 
            dp[i] += dp[k] * 2;
    }
    cout << dp[N/2] << "\n";

}