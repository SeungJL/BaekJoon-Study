#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    long long L = 0, R = 0;
    while (a != 1 || b != 1) {
        if (a == 1) {
            R += b - 1;
            break;
        }
        if (b == 1) {
            L += a - 1;
            break;
        }

        if (a < b) {
            b = b - a;
            R++;
        }
        else {
            a = a - b;
            L++;
        }
    }
    printf("%lld %lld", L, R);
    return 0;
}
