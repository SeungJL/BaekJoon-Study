#include<bits/stdc++.h>
using namespace std;
int n;
int s[21][21];
pair<vector<int>,vector<int>> get_team(int);
int get_score(vector<int>&);
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> s[i][j];
        }
    }
    int ans = 0x7fffffff;
    for(int i = 0; i < (1<<n); i++){
        vector<int> ateam;
        vector<int> bteam;
        tie(ateam, bteam) = get_team(i);
        // cout<<"ateam : ";
        // for(auto it: ateam){
        //     cout<< it<<" ";
        // }
        // cout<<"bteam : ";
        // for(auto it: bteam){
        //     cout<< it <<" ";
        // }
        // cout<<endl;
        int ascore = get_score(ateam);
        int bscore = get_score(bteam);
        // cout<<"ascore"<<ascore<<"bscore"<<bscore<<endl;
        ans = min(ans, abs(ascore - bscore));
    }
    cout << ans << endl;
}
pair<vector<int>,vector<int>> get_team(int bits){
    // get all 1's
    vector<int> ateam;
    vector<int> bteam;
    for(int i=0 ; i<n; i++){
        if((bits & (1<<i)) > 0){
            ateam.push_back(i);
        }else{
            bteam.push_back(i);
        }
    }
    return make_pair(ateam, bteam);
}
int get_score(vector<int>& team){
    int score = 0;
    for(int i=0; i<team.size(); i++){
        for(int j=i+1; j<team.size(); j++){
            score += (s[team[i]][team[j]] + s[team[j]][team[i]]); 
        }
    }
    return score;
}