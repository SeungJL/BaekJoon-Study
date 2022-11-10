#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, N;
    cin >> L >> N;
    bool *cake = new bool[L];

    int max = 0, max_index = 0;g
    int ans = 0, ans_index = 0;

    for (int i = 0; i < N; i++) {
        int P, K;
        cin >> P >> K;
        int cnt = 0;
        for (int j = P - 1; j < K; j++) {
            if (cake[j] == true) continue;
            cake[j] = true;
            cnt++;
        }
        if (cnt > ans) {
            ans = cnt;
            ans_index = i;
        }
        if ((K - P + 1) > max) {
            max = (K - P + 1);
            max_index = i;
        }
    }
    cout << max_index + 1 << "\n" << ans_index + 1;
    return 0;
}