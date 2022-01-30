#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, a, b;
    scanf("%d %d %d", &N, &a, &b);
    int cnt = 0;
    while (true) {
        //a, b가 같은 라운드에서 만나면 반복문 종료
        if (a == b) break;

        // 한 라운드를 거칠 때마다 a, b의 번호 줄이기.
        // ex) a = 8, b = 9
        // 1 round -> a = 4, b = 5
        // 2 round -> a = 2, b = 3
        // 3 round -> a = 1, b = 2
        // 4 round -> a = 1, b = 1

        if (a % 2 == 0) a /= 2;
        else a = a / 2 + 1;

        if (b % 2 == 0) b /= 2;
        else b = b / 2 + 1;

        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}