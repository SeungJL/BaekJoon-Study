#include <bits/stdc++.h>

using namespace std;

int dp[10001];
int grape[10001];

/*
    6 10 13 9 8 1

    dp[1] =  grape[1] → 6

    dp[2] = grape[1] + grape[2] → 16

    dp[3]부터 ..

    i번째

    1. (1, 2) dp[i-1]
     → i번째 포도주를 마시지 않는 경우
     (i-1번째까지의 최댓값)

    2. (1, 3) dp[i-2]+grape[i]
     → i-1번째 포도주를 마시지 않고 i번째 포도주를 마시는 경우
     (i-2번째까지의 최댓값 + i번째 포도주)

    3. (2, 3) dp[i-3]+grape[i-1]+grape[i]
     → i-2번째 포도주를 마시지 않고 i-1, i번째 포도주를 마시는 경우
     (i-3번째까지의 최댓값 + i-1, i번째 포도주)
 */
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &grape[i]);
    }
    dp[1] = grape[1];
    dp[2] = grape[1] + grape[2];
    for (int i = 3; i <= N; i++) {
        dp[i] = max(dp[i-1], max(dp[i-2]+grape[i], dp[i-3]+grape[i-1]+grape[i]));
    }
    printf("%d", dp[N]);

    return 0;
}