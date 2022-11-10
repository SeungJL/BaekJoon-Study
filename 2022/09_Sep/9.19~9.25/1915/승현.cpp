#include<bits/stdc++.h>
using namespace std;
int n, m;
string s[1001];
int dp[1001][1001];
int main(){
    cin >> n >> m;
    cin.get();
    for(int i = 1; i <= n; i++){
        getline(cin, s[i]);
        s[i] = " " + s[i];

    }

    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i][j] == '1'){
                // s[i][j] = 1;
                dp[i][j] = min(dp[i-1][j] , min(dp[i][j-1] , dp[i-1][j-1])) + 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <=m; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << pow(ans, 2) << endl;


}