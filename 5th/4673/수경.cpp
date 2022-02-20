#include <bits/stdc++.h>

using namespace std;

bool d[10001];

int main() {
    for (int i = 1; i <= 10000; i++) {
        int tmp = i;
        int sum = 0;
        while (tmp) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (i + sum > 10000) continue;
        d[i + sum] = true;
    }
    for (int i = 1; i <= 10000; i++) {
        if (d[i] == false) printf("%d\n", i);
    }
    return 0;
}