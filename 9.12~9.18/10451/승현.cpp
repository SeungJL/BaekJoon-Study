#include<bits/stdc++.h>
using namespace std;
int t,n;
int dfs(vector<int>&, vector<bool>&, int);
int main(){
 cin >> t;
 for(int i = 0; i < t; i++){
    int cnt = 0;
    cin>>n;
    vector<int> a;
    a.push_back(-1); // -1남기기
    for(int j = 1; j <= n; j++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    vector<bool> b;
    b.push_back(true); //0번 남기기
    for(int j = 1; j <= n; j++){
        b.push_back(false);
    }

    for(int j = 1; j <= n; j++){
        if(!b[j]){
            int fin = dfs(a, b, j);
            // cout<<"j"<<j <<"fin"<<fin<<endl;
            if(fin == j) cnt += 1;
        }
    }
    cout << cnt << endl;

 }

}
int dfs(vector<int>& a, vector<bool>& b, int i){
    int ans = 0;
    b[i] = true;
    if(!b[a[i]]){
        return dfs(a, b, a[i]);
    } else{
        return a[i];
    }

}