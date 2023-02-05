#include <iostream>
using namespace std;
long long dp[101][11];

int main() {
    int n;
    cin >> n;

    for(int i=0; i<101; i++) {
        dp[i][10] = 0;
    }

    for(int i=0; i<10; i++) {
        dp[0][i] = 1;
    }

    for(int i=1; i<n; i++) {
        for(int j=0; j<10; j++) {
            if(j == 0) {
                dp[i][j] = dp[i-1][j+1] % 1000000000;
            } else {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
            }
            
        }
    }


    // for(int i=0; i<10; i++) {
    //     for(int j=0; j<11; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    long long ans = 0;
    for(int i=1; i<10; i++) {
        ans += dp[n-1][i];
    }
    cout << ans % 1000000000;
}