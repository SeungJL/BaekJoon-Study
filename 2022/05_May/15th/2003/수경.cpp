#include <bits/stdc++.h>

using namespace std;

int A[10001];
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 0;

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < N; i++) {
        int sum = 0;
        int j = i;
        while (j < N && sum < M) {
            sum += A[j];
            j++;
        }
        if (sum == M) cnt++;
    }
    cout << cnt;
    return 0;
}