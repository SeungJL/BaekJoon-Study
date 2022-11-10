#include <bits/stdc++.h>

using namespace std;


int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        unordered_set<int> memo;
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            int tmp;
            scanf("%d", &tmp);
            memo.insert(tmp);
        }
        int M;
        scanf("%d", &M);
        for (int i = 0; i < M; i++) {
            int tmp;
            scanf("%d", &tmp);
            if (memo.find(tmp) != memo.end()) printf("1\n");
            else printf("0\n");

        }
    }

    return 0;
}