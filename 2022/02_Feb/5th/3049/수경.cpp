#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = N * (N - 1) * (N - 2) * (N - 3) / (4 * 3 * 2 * 1);
    cout << ans;

    return 0;
}

/*
 * nC4
 *
 */