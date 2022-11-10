#include<bits/stdc++.h>
using namespace std;
int n, m;
string s;
vector<int> store;
int get_p(int);
int get_ans();
int main(){
    cin >> n >> m;
    cin.get();
    getline(cin, s);
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'I'){
            int j;
            j = get_p(i);
            i += j * 2;
            store.push_back(j);
        }
    }
    int ans = get_ans();
    cout << ans << endl;
}
int get_p(int i){
    
    if(i+2 < s.length() && s[i+1] == 'O' && s[i+2] == 'I'){
        return get_p(i + 2) + 1;
    } else{
        return 0;
    }    
}

int get_ans(){
    int ans = 0;
    for(auto it : store){
        ans += max(0, it + 1 - n);
    }
    return ans;
}