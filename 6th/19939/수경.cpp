#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= K; i++) N -= i;

    if (N < 0) {
        cout << -1;
    } else if (N % K == 0) cout << K - 1;
    else cout << K;


    return 0;
}
/*
 * //6 3
 * 1 2 3
 * 2
 *
 * 7 3
 * 1 2 4
 * 3
 *
 * 8 3
 * 1 3 4
 * 3
 *
 * //9 3
 * 2 3 4
 * 2
 *
 * 10 3
 * 2 3 5
 * 3
 *
 * 11 3
 * 2 4 5
 * 3
 *
 * //12 3
 * 3 4 5
 *
 *
 *
 *
 *
 */