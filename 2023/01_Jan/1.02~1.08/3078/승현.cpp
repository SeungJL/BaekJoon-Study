#include<iostream>
using namespace std;
int n, k;
long long dp[300001][25]; // dp[n][m] : idx n의 길이가 n일때, k범위 내에 속하는 학생의 수
int str[300001];
int main(){
    cin >> n >> k;
    cin.get();
    for(int i = 1; i <= n; i++){
        string s;
        getline(cin,s);
        str[i] = s.length();
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 24; j++){
            int last_idx = max(i - k - 1, 0);
            if(str[i] == j){
                dp[i][j] = dp[i-1][j] + 1;
                dp[i][j] = (str[last_idx] == j) ? (dp[i][j] - 1) : (dp[i][j]); 
                ans += (dp[i][j] - 1);
            }else{
                dp[i][j] = dp[i-1][j];
                dp[i][j] = (str[last_idx] == j) ? (dp[i][j] - 1) : (dp[i][j]);
            }
        }
    }
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= 20; j ++){
    //         cout << dp[i][j] <<"  ";
    //     }
    //     cout <<endl;
    // }
    // cout <<"============="<<endl;
    cout << ans << endl;
}