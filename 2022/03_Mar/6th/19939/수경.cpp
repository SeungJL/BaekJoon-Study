#include <bits/stdc++.h>

using namespace std;


int main() {
    int N, K;
    cin >> N >> K;
    // 1, 2, 3, 4, 5, 6 ... 이렇게 담는 경우(최소)
    for (int i = 1; i <= K; i++) N -= i;

    //최소의 경우도 안 만들어지므로 -1 출력
    if (N < 0) {
        cout << -1;
    }
        //남은 공들을 모든 바구니에 하나씩 집어넣는 경우.
        // N=15 K=5
        // 2 3 4 5 6
    else if (N % K == 0) cout << K - 1;
        // 그 외
        // 8 3
        // 1 3 4
    else cout << K;
    return 0;
}