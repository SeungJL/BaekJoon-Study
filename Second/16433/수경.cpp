#include <bits/stdc++.h>

using namespace std;


//2가지 유형의 당근밭. 조건문으로 구분
int main() {
    int N, R, C;
    scanf("%d %d %d", &N, &R, &C);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i % 2 == j % 2) {
                if ((R + C) % 2 == 0) printf("v");
                else printf(".");
            } else {
                if ((R + C) % 2 == 0) printf(".");
                else printf("v");
            }
        }
        printf("\n");
    }

    return 0;
}
