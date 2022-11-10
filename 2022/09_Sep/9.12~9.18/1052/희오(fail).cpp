// 1052

#include <iostream>
#include <vector>

using namespace std;

#define INF 1000000000
int N, K, res;

void solve(int n, int last, int cnt) {
    if (cnt == 0) {
        if (last - n < res) res = last - n;
        return;
    }

    if (cnt == 1) {
        int i = 1;
        while (i < n) i *= 2;
        solve(n, i, cnt - 1);
        return;
    }

    for (int i=last; i>0; i/=2) {
        if (n - i >= 0) solve(n - i, i, cnt - 1);
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    cin >> N >> K;

    if (N == K) {
        cout << "0\n";
        return 0;
    }

    res = INF;
    int i = 1;
    while (i*2 < N) i *= 2;
    solve(N, i, K);
    (res == INF) ? cout << "-1\n" : cout << res << endl;
}

