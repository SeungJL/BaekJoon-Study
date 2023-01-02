#include<iostream>
using namespace std;

void dfs(string& s);
int n;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    string s;
    s += "1";
    dfs(s);
    s.pop_back();
    s += "2";
    dfs(s);
    s.pop_back();
    s += "3";
    dfs(s);
    s.pop_back();
     
}
void dfs(string& s){
    // cout <<"string" << s<<endl;
    char lastc = s[s.length() - 1];
    
    if(s.length() == 1){
        s = s + "1";
        dfs(s);
        s.pop_back();
        s = s + "2";
        dfs(s);
        s.pop_back();
        s = s + "3";
        dfs(s);
        s.pop_back();
        return;
    } 
    bool real_ok = true;
    for(int i = s.length() - 2; i >=0; i--){
        if((i + 1) < (s.length() - 1 - i)) break;
        
        if(s[i] == lastc){
            int tok = s.length() - 2 - i;
            bool ok = true;
            while(tok){
                if(s[tok + i] != s[tok + 2 * i - s.length() + 1]){
                    ok = false;
                    break;
                } 
                tok -= 1;
            }
            if(ok){
                real_ok = false;
                break;
            }
            
        }
    }
    if(real_ok){
        if(s.length() == n){
            cout << s << endl;
            exit(0);
        }
        s = s + "1";
        dfs(s);
        s.pop_back();
        s = s + "2";
        dfs(s);
        s.pop_back();
        s = s + "3";
        dfs(s);
        s.pop_back();
    }
}