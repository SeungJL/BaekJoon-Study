#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);

    long long q = sqrt(n);
    //만약 n이 제곱수였다면 q*q == n 일 것이다.
    // q^2>=n인 q를 구해야 하므로, q*q<n이라면 q를 1 더해준다.
    if (q * q < n) q++;

    printf("%lld", q);

    return 0;
}
