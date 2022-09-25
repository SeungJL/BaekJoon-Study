#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    getline(cin, s);
    int ans = 0;
    int cur_stick = 0; //현재 진행중인 막대
    for(int i = 0; i < s.length(); i++){
        // cout<<"i"<<i<<"cur_stick"<<cur_stick<<"ans"<<ans<<endl;
        if(s[i] == '('){
            if(s[i+1] == ')'){ // laser
                ans += cur_stick;
                i += 1;
                continue;
            }else{
                cur_stick += 1;
            }
        }else{
            ans += 1;
            cur_stick -= 1;
        }
    }
    cout<<ans<<endl;
}