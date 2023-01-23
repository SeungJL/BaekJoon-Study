#include <iostream>
using namespace std;
int song[51] = { 0, };
bool cansong = false;
int n, s, m;
int answer = 0;
bool dp[51][1001] = { false, }; 

void dfs(int start, int depth) {

    if(start > m || start < 0) return;
    // cout << "depth: " << depth << " start: " << start << "\n";
    if(depth == n) {
       
        if(start > answer)  {
            answer = start;
        }
        cansong = true;
        return;
    }

    if(start + song[depth] <= m) {
        // cout << song[depth] << "\n";
        if(dp[depth + 1][start + song[depth]] == false) {
            dp[depth + 1][start + song[depth]] = true;
            dfs(start + song[depth], depth + 1);
        }
    }
    
    if(start - song[depth] >= 0) {
        // cout << song[depth] << "\n";
        if(dp[depth + 1][start - song[depth]] == false) {
            dp[depth + 1][start - song[depth]] = true;
            dfs(start - song[depth], depth + 1);
        }
        
    }
    
}


int main() {
  
    cin >> n >> s >> m;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        song[i] = input;
    }

    dp[0][s] = true;
    dfs(s, 0);
    
    if(cansong) {
        cout << answer;
    } else {
        cout << -1;
    }
   
}