#include <bits/stdc++.h>

using namespace std;

int glass[1000][1000];
int dp[1000][1000];

int di[3] = {1, 1, 1};
int dj[3] = {-1, 0, 1};


int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &glass[i][j]);
            if (i == 0) {
                dp[i][j] = glass[i][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (glass[i][j] == 0) continue;
            for (int k = 0; k < 3; k++) {
                int _i = di[k] + i;
                int _j = dj[k] + j;

                if (_i < 0 || _i >= N || _j < 0 || _j >= M || glass[_i][_j] == 0) continue;

                dp[_i][_j] += dp[i][j];
                dp[_i][_j] %= 1000000007;
            }
        }
    }



    long long ans=0;
    for (int i = 0; i < M; i++) {
        ans += dp[N - 1][i];
        ans %= 1000000007;
    }
    printf("%lld", ans);

    return 0;
}