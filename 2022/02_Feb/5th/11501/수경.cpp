#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        vector<int> stock;
        for (int i = 0; i < N; i++) {
            int tmp;
            scanf("%d", &tmp);
            stock.push_back(tmp);
        }
        long long ans = 0;
        int max = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (stock[i] > max) {
                max = stock[i];
            } else {
                ans += (max - stock[i]);
            }
        }
        printf("%lld\n", ans);

    }
    return 0;
}
/*
 * 10 7 6
 * 0
 *
 *
 * 3 5 9
 * -3-5+18 = 10
 *
 *
 * 1 1 3 1 2
 * 5
 * -1-1+6-1+2
 *
 * 1 2 3 2 4
 * 8
 *
 */