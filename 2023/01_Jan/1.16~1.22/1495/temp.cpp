#include<iostream>
#include<cstring>
using namespace std;
void dfs(int c, int score);
int n, s, m;
int a[51];
bool dp[51][1001];
int answer = -100000;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    //   memset(dp, -1, sizeof(dp));
    cin >> n >> s >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, s);
    if (answer < 0) {
        cout << -1 << endl;
    }
    else {
        cout << answer << endl;
    }

}
void dfs(int c, int score) {
    int ans = -999999;
    if (c == n + 1)
    {
        if (score > answer) { answer = score; }
        return;
    }
    if (dp[c][score]) return;
    int nxtscore = score + a[c];
    if (nxtscore <= m) {
        dfs(c + 1, nxtscore);
    }
    nxtscore = score - a[c];
    if (nxtscore >= 0) {
        dfs(c + 1, nxtscore);
        // ans = ans > p ? ans : p;
    }

    dp[c][score] = true;
    //return;
}