#include<iostream>
#include<cstring>
using namespace std;
int dfs(int c,int score);
int n, s, m;
int a[51];
int dp[51][1001];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> s >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = dfs(1, s);
    if(ans < 0){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

}
int dfs(int c,int score){
    int ans = -999999;
    if(c == n + 1) return score;
    if(dp[c][score] != -1) return dp[c][score];
    int nxtscore = score + a[c];
    if(nxtscore <= m){
        ans = dfs(c+1, nxtscore);
    }
    nxtscore = score - a[c];
    if(nxtscore >= 0){
        int p = dfs(c+1, nxtscore);
        ans = ans > p ? ans : p;
    }
    return dp[c][score] = ans;
}