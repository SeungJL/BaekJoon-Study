#include <bits/stdc++.h>

using namespace std;

int dp[50001];
/*
 * 제곱수(four squares)일 경우,
 * 자연수 하나의 제곱으로 온전히 나타낼 수 있으므로
 * 1개의 최소 개수의 제곱수 합으로 표현할 수 있다.
 */
int main() {
    int n;
    cin >> n;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int min = INT_MAX;
        if ((int) sqrt(i) * (int) sqrt(i) == i) {
            min = 1;
        } else {
            for (int j = 1; j * j < i; j++) {
                //만들 수 있는 조합 중 dp의 최소값 구하기
                int tmp = dp[j * j] + dp[i - j * j];
                if (tmp < min) min = tmp;
            }
        }
        dp[i] = min;
    }
    cout << dp[n];

    return 0;
}