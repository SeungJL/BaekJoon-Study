// 플로이드 와셜 easy버전 풀이?

#include<bits/stdc++.h>
using namespace std;
bool a[201][201];
int n, m;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            bool tmp;
            cin >> tmp;
            a[i][j] = tmp;
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            for(int k = 1; k <=n; k++){
                // 원래는 d[j][k] = min(d[j][k], d[j][i] + d[i][k])여야함
                if(a[j][i] && a[i][k]){
                    a[j][k] = true;
                }
            }
        }
    }
    
    int cur, nxt;
    bool ans = true;
    for(int i = 0; i < m; i++){
        if(i == 0) cin >> cur;
        else{
            cin >> nxt;
            if(cur != nxt && !a[cur][nxt]){
                ans = false;
            }
            cur = nxt;
        }
        
    }

    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;

