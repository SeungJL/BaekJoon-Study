#include<bits/stdc++.h>
using namespace std;
int n, m;
bool visited[1500001];
vector<int> no;
// void get_possible(priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>& q);
pair<bool,int> can_click(int i);
int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int temp;
        cin >> temp;
        no.push_back(temp);        
    }
    

    // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    // q.push(make_pair(0,100));
    // visited[100] = true;
    int ans = 0x7fffffff;
    for(int i=0; i<1000000; i++){
        if(i == 100){
            ans = min(ans, abs(100 - n));
        }else{
            bool ok;
            int digit;
            tie(ok,digit) = can_click(i);
            if(ok){
                ans = min(ans, digit + abs( i - n));
            }
        }
        
    }
    cout<<ans<<endl;

}

pair<bool,int> can_click(int i){
    bool really_ok = true;
    if(i == 0){
        for(auto nope: no){
            if(i == nope){
                return make_pair(false, 1);
            }
        }
        return make_pair(true,1);
    }else{
        int pow=0;
        int j = i;
        // cout<<"i start"<<i<<endl;
        while(j > 0){
            pow+=1;
            int mod = j % 10;
            bool ok = true;
            for(auto nope: no){
                // cout<<"mod"<<mod<<"nope"<<nope<<endl;
                if(mod == nope){
                    ok = false;
                    break;
                }
            }
            if(!ok){
                really_ok = false;
                break;
            }
            j /= 10;
        }
        // cout<<"can_click"<<i<<"really ok"<<really_ok<<"digit"<<pow<<endl;
        return make_pair(really_ok,pow);
    }
    
    

}