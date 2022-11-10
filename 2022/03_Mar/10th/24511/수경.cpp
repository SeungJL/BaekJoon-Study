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
/*
 *
 * 4
 * 0 1 1 0
 *
 * 1 2 3 4
 * 큐 스 스 큐
 *
 * 3
 * 2 4 7
 *
 * 2 삽입
 * 1(큐)-> 2 / 1 return
 * 2(스) -> 2 / 1 return
 * 3(스) -> 3 / 1 return
 * 4(큐) -> 1 / 4 return
 *
 */