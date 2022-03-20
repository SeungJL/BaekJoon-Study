#include <bits/stdc++.h>

using namespace std;

vector<int> ele;
vector<int> idx;
vector<int> C;

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == 0) idx.push_back(i);
    }

    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        ele.push_back(tmp);
    }
    for (int i = idx.size() - 1; i >= 0; i--) {
        C.push_back(ele[idx[i]]);
    }

    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int tmp;
        scanf("%d", &tmp);
        C.push_back(tmp);
    }

    for (int i = 0; i < M; i++) {
        printf("%d ", C[i]);
    }

    return 0;
}
