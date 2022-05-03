#include <bits/stdc++.h>

using namespace std;

int dp[4001][4001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string A, B;
    cin >> A >> B;
    int max_ans = 0;
    for (int j = 0; j < B.length(); j++) {
        if (A[0] == B[j]) {
            dp[0][j] = 1;
            max_ans = 1;
        }
    }

    for (int i = 1; i < A.length(); i++) {
        for (int j = 0; j < B.length(); j++) {
            if (A[i] == B[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max_ans = max(dp[i][j], max_ans);
            }
        }
    }

    printf("%d\n", max_ans);


    return 0;
}

/*
 * ABRACADABRA
 * ECADADABRBCRDARA
 */