#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, h, p, q;
    scanf("%d %d", &w, &h);
    scanf("%d %d", &p, &q);
    int t;
    scanf("%d", &t);

    int a = t % (2 * w);
    int b = t % (2 * h);

    int x = 1, y = 1;
    for (int i = 0; i < a; i++) {
        if (p == w || p == 0) {
            x *= -1;
        }
        p += x;
    }
    for (int i = 0; i < b; i++) {
        if (q == h || q == 0) {
            y *= -1;
        }
        q += y;
    }
    printf("%d %d\n", p, q);

    return 0;
}