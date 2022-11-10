#include <bits/stdc++.h>

using namespace std;
int N, M;
string x[50];

int searchSquare(int _i, int _j) {
    char pivot = x[_i][_j];
    int max = 0;
    for (int i = _i + 1; i < N; i++) {
        if (x[i][_j] != pivot) continue;
        int gap = i - _i;
        if (_j + gap > M) continue;
        if (x[i][_j + gap] != pivot) continue;
        if (x[_i][_j + gap] != pivot) continue;

        if (max < gap) max = gap;
    }
    max++;
    return max * max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int tmp = searchSquare(i, j);
            if (max < tmp) max = tmp;
        }
    }

    cout << max;

    return 0;
}