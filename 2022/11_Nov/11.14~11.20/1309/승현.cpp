#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
long long dp[100001][3];
long long dfs(int, int);
int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n;
    dp[n][0] = 1;
    dp[n][1] = 1;
    dp[n][2] = 1;
    cout << dfs(0,0);
    
}
long long dfs(int x, int mode){
    if(dp[x][mode] != -1) return dp[x][mode];
    if(mode == 0) return dp[x][mode] = (dfs(x+1,0) + dfs(x+1,1) + dfs(x+1,2)) % 9901;
    else if(mode == 1) return dp[x][mode] = (dfs(x+1,0) + dfs(x+1,2)) % 9901;
    else return dp[x][mode] = (dfs(x+1,0) + dfs(x+1,1)) % 9901;
}