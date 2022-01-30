#include <bits/stdc++.h>

using namespace std;
vector<int> a;

int main() {
    int N;
    scanf("%d", &N);

    //수열 입력받기
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        a.push_back(tmp);
    }

    // 이전 수열을 찾아주는 함수
    if (prev_permutation(a.begin(), a.end())) {
        for (int i = 0; i < N; i++) printf("%d ", a[i]);
    } else printf("-1\n");

    return 0;
}