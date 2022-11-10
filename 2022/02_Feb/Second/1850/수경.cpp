#include <bits/stdc++.h>

using namespace std;

//유클리드 호제법
long long GCD(long long a, long long b) {
    if (a % b == 0) return b;
    return GCD(b, a % b);
}

int main() {

    long long A, B;
    scanf("%lld %lld", &A, &B);

    if (A < B) swap(A, B);

    long long cnt = GCD(A, B);

    for (long long i = 0; i < cnt; i++) {
        printf("1");
    }

    return 0;
}