#include <bits/stdc++.h>

using namespace std;

int GCD(int M, int N) {
    if (N == 0) return M;
    return GCD(N, M % N);
}

int LCM(int M, int N) {
    return M * N / GCD(M, N);
}

int calendar(int M, int N, int x, int y) {
    // x에 M을 계속 더한 수 == M으로 나누었을 때 x인 연도
    // 멸망의 해 == M, N의 최소공배수 (유클리드 호제법)
    for (int i = x; i <= LCM(M, N); i += M) {
        int k;  // 연도를 N으로 나눈 나머지가 0이면 N 대입.
        if (i % N == 0) k = N;
        else k = i % N;

        // 나머지가 y랑 같으면 해당 연도 반환
        if (k == y) return i;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        cout << calendar(M, N, x, y) << "\n";
    }
    return 0;
}