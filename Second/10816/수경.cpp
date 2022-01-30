#include <bits/stdc++.h>

using namespace std;

int plusNum[10000001];
int minusNum[10000001];
int zeroNum = 0;

//범위가 정해져 있으므로 게수정렬 이용
int main() {
    int N, M;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp > 0) plusNum[tmp]++;
        else if (tmp < 0) minusNum[-tmp]++;
        else zeroNum++;
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp > 0) printf("%d ", plusNum[tmp]);
        else if (tmp < 0) printf("%d ", minusNum[-tmp]);
        else printf("%d ", zeroNum);
    }

    return 0;
}