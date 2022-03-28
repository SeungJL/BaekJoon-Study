#include <bits/stdc++.h>

using namespace std;

int x[100][100];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &x[i][j]);
        }
    }

    int sum = N * M * 2;
    //왼쪽 옆
    for (int i = 0; i < N; i++) {
        sum += x[i][0];
        for (int j = 0; j < M - 1; j++) {
            if (x[i][j] < x[i][j + 1]) sum += (x[i][j + 1] - x[i][j]);
        }
    }
    //오른쪽 옆
    for (int i = 0; i < N; i++) {
        sum += x[i][M - 1];
        for (int j = M - 1; j > 0; j--) {
            if (x[i][j] < x[i][j - 1]) sum += (x[i][j - 1] - x[i][j]);
        }
    }

    for (int j = 0; j < M; j++) {
        sum += x[N - 1][j];
        for (int i = N - 1; i > 0; i--) {
            if (x[i][j] < x[i - 1][j]) sum += (x[i - 1][j] - x[i][j]);
        }
    }

    for (int j = 0; j < M; j++) {
        sum += x[0][j];
        for (int i = 0; i < N - 1; i++) {
            if (x[i][j] < x[i + 1][j]) sum += (x[i + 1][j] - x[i][j]);
        }
    }

    printf("%d\n", sum);


    return 0;
}
/*
 * 1 3 4
 * 2 2 3
 * 1 2 4
 *
 * 위, 아래 -> 9 + 9
 * 왼쪽 옆
 * 1+2+1
 * 2+1
 * 1+1+2
 *
 * 오른쪽 옆
 * 4
 * 3
 * 4
 *
 * 앞
 * 1+1
 * 2+1
 * 4+1
 *
 * 뒤
 * 1+1
 * 3
 * 4+1
 */