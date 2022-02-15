#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int tmp = i;
        for (int j = 2; j <= K; j++) {
            while (tmp % j == 0) tmp /= j;
        }
        if (tmp == 1) ans++;
    }
    printf("%d\n", ans);

    return 0;
}
