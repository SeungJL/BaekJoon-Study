//에라토스테네스의 체

#include <bits/stdc++.h>

using namespace std;

int eratosthenes[10001];

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 2; i <= 10001; i++) {
        if (eratosthenes[i] == 1) continue;
        for (int j = i + i; j <= 10001; j += i) {
            if (eratosthenes[j] == 1) continue;
            eratosthenes[j] = 1;
        }
    }

    while (T--) {
        int n;
        scanf("%d", &n);
        int a, b;
        for (int i = n / 2; i >= 0; i--) {
            if (eratosthenes[i] == 1) continue;
            a = i;
            if (eratosthenes[n - a] == 1) continue;
            b = n - a;
            break;
        }
        printf("%d %d\n", a, b);
    }

    return 0;
}