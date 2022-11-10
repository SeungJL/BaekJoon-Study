#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<long long> hapchae(vector<long long> a, int cnt);
int main(){
    cin >> n >> m;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    hapchae(a, 0);
}
vector<long long> hapchae(vector<long long> a, int cnt){
    if(cnt == m){
        long long ans = 0;
        for(auto it : a){

            ans += it;
        }
        cout << ans << endl;
        exit(0);
    }else{
        // vector<int> newa(a);
        //get idx0 and 1
        int i = 2;
        bool ok = false;
        long long target = (a[0] + a[1]);
        for(; i < a.size(); i++){
            if(target < a[i]){
                ok = true;
                for(int j = 2; j < i; j++){
                    a[j - 2] = a[j];
                }
                a[i - 1] = target; 
                a[i - 2] = target;
                break;
            }
        }        
        if(!ok){
            for(int i = 2; i < a.size(); i++){
                a[i - 2] = a[i];
            }
            a[a.size() - 2] = target;
            a[a.size() - 1] = target; 
        }
        // //sort
        // cout <<"=============="<<endl;
        // for(auto it : a){
        //     cout << it <<" ";
        // }
        // cout << endl;
        hapchae(a, cnt + 1);
    }
}

