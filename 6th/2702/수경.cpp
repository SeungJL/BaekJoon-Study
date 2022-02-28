#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

int LCM(int a, int b, int gcd) {
    return a / gcd * b / gcd * gcd;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        int gcd, lcm;
        gcd = GCD(a, b);
        lcm = LCM(a, b, gcd);
        cout << lcm << " " << gcd << '\n';
    }
    return 0;
}