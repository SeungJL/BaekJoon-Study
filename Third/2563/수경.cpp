#include <bits/stdc++.h>

using namespace std;

int paper[101][101];

void paint(int x, int y) {
    for (int i = x; i < x + 10; i++) {
        for (int j = y; j < y + 10; j++) {
            paper[i][j] = 1;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        paint(x, y);
    }

    int total = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (paper[i][j] == 1) total++;
        }
    }
    printf("%d", total);
    return 0;
}