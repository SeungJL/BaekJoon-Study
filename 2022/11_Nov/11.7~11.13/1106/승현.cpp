#include <iostream>
#include <cstring>
using namespace std;
int c, n;
int a[21][2]; // 비용 / 고객의 수
int dp[5001][21]; 
int main(){
    memset(dp, 0x3f, sizeof(dp));
    cin >> c >> n;
    for(int i = 1; i <= n ;i++){
        cin >> a[i][0] >> a[i][1];
        dp[a[i][1]][i] = a[i][0]; // init을 해주어야함
    }

    for(int i = 1; i <= 5000; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            if(a[j][1] <= i){ 
                dp[i][j] = min(dp[i - a[j][1]][j] + a[j][0] , dp[i][j]);
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for(int i = c; i <= 5000; i++){
        ans = min(ans, dp[i][n]);
    }
    cout << ans << endl;
    

}