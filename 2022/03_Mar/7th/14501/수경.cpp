#include <bits/stdc++.h>

using namespace std;


// i, T, P
int T[16];
int P[16];
int maxAns = 0;
int N;

void DFS(int index, int ans, int prev) {

    if (index > N + 1) {
        if (maxAns < ans - P[prev]) maxAns = ans - P[prev];
        return;
    } else if (index == N + 1) {
        if (maxAns < ans) maxAns = ans;
        return;
    }
    for (int i = index; i <= N; i++) {
        DFS(i + T[i], ans + P[i], i);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &T[i], &P[i]);

    }
    DFS(1, 0, 0);
    printf("%d\n", maxAns);
    return 0;
}
