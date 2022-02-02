#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    printf("<");

    queue<int> Q;
    for (int i = 1; i <= N; i++) Q.push(i);

    while (Q.size() != 1) {
        for (int i = 0; i < K - 1; i++) {
            Q.push(Q.front());
            Q.pop();
        }
        printf("%d, ", Q.front());
        Q.pop();
    }

    printf("%d>", Q.front());
    return 0;
}