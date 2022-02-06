#include <bits/stdc++.h>

using namespace std;

//최대 공약수(유클리드 호제법)
long long GCD(long long A, long long B) {
    if (A % B == 0) return B;
    return GCD(B, A % B);
}

//최소공배수
long long LCM(long long A, long long B) {
    long long gcd = GCD(A, B);
    return (A / gcd) * (B / gcd) * gcd;
}

int main() {
    long long A, B;
    scanf("%lld %lld", &A, &B);
    printf("%lld", LCM(A, B));


    return 0;
}