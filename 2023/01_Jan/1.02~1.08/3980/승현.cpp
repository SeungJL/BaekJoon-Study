#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int c;
int a[11][11];
int dfs(int idx, vector<bool>& taken);
int main(){
    cin >> c;
    for(int t = 0; t < c; t++){
        memset(a, 0x00, sizeof(a));
        for(int i = 0; i < 11; i++){
            for(int j = 0; j < 11; j++){
                cin >> a[i][j];
            }
        }
        vector<bool> taken(11, false);
        cout << dfs(0, taken) << endl;
    }
    

}
int dfs(int idx, vector<bool>& taken){
    // cout << idx << endl;
    int ans = -9999999;
    if(idx == 11) return 0;
    for(int i = 0; i < 11; i++){
        if(a[idx][i] != 0 && !taken[i]){
            taken[i] = true;
            ans = max(ans, a[idx][i] + dfs(idx+1, taken));
            taken[i] = false;
        }
    }
    return ans;

}

