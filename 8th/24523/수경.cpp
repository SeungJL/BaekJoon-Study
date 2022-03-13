#include <bits/stdc++.h>

using namespace std;

vector<int> V;

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        V.push_back(tmp);
    }

    for (int i = 0; i < N; i++) {
        int j = i + 1;
        for (; j < N; j++) {
            if (V[i] != V[j]) break;
        }
        for (int k = 0; k < j - i; k++) {
            if (j + 1 > N) printf("-1 ");
            else printf("%d ", j + 1);
        }
        i += j - i - 1;
    }
    return 0;
}
/*
 * 3 3 1 1 4 4
 *
 */