#include <bits/stdc++.h>

using namespace std;

vector<int> L;

long long calculateLen(long long len) {
    long long cnt = 0;
    for (int i = 0; i < L.size(); i++) {
        cnt += L[i] / len;
    }
    return cnt;
}

int main() {
    int K, N;
    scanf("%d %d", &K, &N);
    for (int i = 0; i < K; i++) {
        int tmp;
        scanf("%d", &tmp);
        L.push_back(tmp);
    }
    sort(L.begin(), L.end());

    long long start = 1;
    long long end = L[L.size() - 1];

    long long ans = 0;
    while (start <= end) {
        long long len = (start + end) / 2;
        long long cnt = calculateLen(len);
        if (cnt >= N) {
            start = len + 1;
            ans = max(ans, len);
        } else end = len - 1;
    }
    printf("%lld", ans);


    return 0;
}
/*
 * 802
 * 743
 * 457
 * 539
 *
 */