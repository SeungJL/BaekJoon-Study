#include<iostream>
#include<stack>
using namespace std;
string s;
int main(){
    getline(cin, s);
    stack<char> st;
    int ans = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            if(i+1 < s.length() && s[i+1] == ')'){
                ans += st.size();
                i += 1;
            }else{
                st.push('(');
            }
        }else{
            st.pop();
            ans += 1;
        }
    }

    cout << ans << endl;
}