#include <bits/stdc++.h>

using namespace std;

int x[1000000];

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &x[i]);
    }
    int maxAns = 0;
    for (int i = 1; i < N - 1; i++) {
        int pivot = x[i];
        int smaller = min(x[i - 1], x[i + 1]);
        maxAns = max(smaller + pivot, maxAns);
    }
    maxAns = max(x[0], maxAns);
    maxAns = max(x[N - 1], maxAns);
    printf("%d\n", maxAns);


    return 0;
}
/*
 * 1 3 2 2
 * 1 2 3 1
 * 1 1 4 0
 *
 * 2 4 3 5 5
 * 2 4 2 6 4
 * 2 4 1 7 3
 * 2 4 0 8 2
 */