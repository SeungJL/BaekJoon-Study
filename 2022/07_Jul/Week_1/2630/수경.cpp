#include <bits/stdc++.h>

using namespace std;

int N;
int w = 0, b = 0;
int paper[128][128];

void check(int start_i, int start_j, int size) {

    int cnt = 0;
    for (int i = start_i; i < start_i + size; i++) {
        for (int j = start_j; j < start_j + size; j++) {
            if (paper[i][j] == 1) cnt++;
        }
    }

    if (cnt == 0) w++;
    else if (cnt == size * size) b++;
    else {
        check(start_i, start_j, size / 2);
        check(start_i, start_j + size / 2, size / 2);
        check(start_i + size / 2, start_j, size / 2);
        check(start_i + size / 2, start_j + size / 2, size / 2);
    }
}


// 0: 하얀색, 1: 파란색
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }
    check(0, 0, N);

    cout << w << "\n" << b;

    return 0;
}