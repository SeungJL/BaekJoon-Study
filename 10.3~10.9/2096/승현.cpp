#include<bits/stdc++.h>
using namespace std;
int n;
int a[2][4];
int dp[2][4];
int dpmax[2][4];
void save_dp();
void reset_dp();
int main(){
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3; j++){
            int temp;
            cin >> temp;
            a[1][j] = temp;
        }
        save_dp();
        reset_dp();
        
    } 

    cout << max(dpmax[0][1],max(dpmax[0][2], dpmax[0][3])) << " ";
    cout << min(dp[0][1],min(dp[0][2], dp[0][3])) << endl;
}
void save_dp(){
    dp[1][2] = a[1][2] + min(dp[0][1], min(dp[0][2], dp[0][3]));
    dp[1][1] = a[1][1] + min(dp[0][1], dp[0][2]);
    dp[1][3] = a[1][3] + min(dp[0][2], dp[0][3]);
    dpmax[1][2] = a[1][2] + max(dpmax[0][1], max(dpmax[0][2], dpmax[0][3]));
    dpmax[1][1] = a[1][1] + max(dpmax[0][1], dpmax[0][2]);
    dpmax[1][3] = a[1][3] + max(dpmax[0][2], dpmax[0][3]);
}
void reset_dp(){
    for(int i = 1 ; i <= 3; i++){
        a[0][i] = a[1][i];
    }
    for(int i = 1 ; i <= 3; i++){
        dp[0][i] = dp[1][i];
    }
    for(int i = 1 ; i <= 3; i++){
        dpmax[0][i] = dpmax[1][i];
    }
}