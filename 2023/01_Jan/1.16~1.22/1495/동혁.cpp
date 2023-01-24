#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)

int N, S, M;
bool dp[51][1001]= {false, };
vector<int> v;
int main() {
    cin >> N >> S >> M;
    dp[0][S] = true;
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        for(int j = 0; j <= M; j++) {
            
            if(dp[i][j] == true) {
                int volume1 = j + temp;
                int volume2 = j - temp;
                if(volume1 <= M && volume1 >= 0) {
                    dp[i+1][volume1] = true;
                }
                if(volume2 <= M && volume2 >= 0) {
                    dp[i+1][volume2] = true;
                }
            }
        }

    }
    for(int i = M; i >= 0; i--) {
        if(dp[N][i] == true) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1;
    return 0;
}