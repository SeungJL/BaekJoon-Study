#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int x[100];
    for (int i = 0; i < N; i++) {
        scanf("%d", &x[i]);
    }
    int result = 0;
    for (int i = N - 1; i > 0; i--) {
        if (x[i - 1] - x[i] >= 0) {
            result += x[i - 1] - x[i] + 1;
            x[i - 1] -= x[i - 1] - x[i] + 1;
        }
    }
    printf("%d", result);
    return 0;
}