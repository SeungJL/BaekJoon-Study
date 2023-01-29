#include <iostream>
using namespace std;

long long dp[1010][10] = { 0, };
int main() {
    int n;
    cin >> n;
    
    for(int i=0; i<10; i++) {
        dp[1][i] = 1;
    }

    for(int i=2; i<1010; i++) {
        for(int j=0; j < 10; j++) {
            long long sum = 0;
            for(int k=j; k < 10; k++) {
                sum += dp[i-1][k];
            }
            dp[i][j] = sum % 10007;
        }
    }

    cout << dp[n+1][0];
}