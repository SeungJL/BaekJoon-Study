# include<iostream>
# include<algorithm>
# include<vector>
using namespace std;
int n;
vector<int> hp;
vector<int> happy;
int dp[101][21];
int maxhappy = -1;
int main(){
    cin >> n;
    hp.push_back(0);
    happy.push_back(0);
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        hp.push_back(p);
    }
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        happy.push_back(p);
    }

    for(int i = 1; i <= 100; i ++){
        for(int j = 1; j <= n ; j++){
            if(i - hp[j] > 0){
                dp[i][j] = max(max(max(dp[i - hp[j]][j -1] + happy[j] , dp[i][j]), dp[i-1][j]), dp[i][j-1]);
            }else{
                
                dp[i][j] = max(max(dp[i][j], dp[i-1][j]), dp[i][j-1]);
            }
        }
    }
    cout << dp[100][n] << endl;

}
