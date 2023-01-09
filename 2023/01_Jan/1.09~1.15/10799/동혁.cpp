#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main() {
    fastio;

    string s;
    stack<char> st;
    int sum = 0;
    cin >> s;

    for(int i = 0; i < s.length() - 1; i++) {
        if(s[i] == '(' && s[i + 1] == ')') {
            sum += st.size();
            i++;
            continue;
        }

        if(s[i] == '(') {
            st.push('(');
            continue;
        }

        st.pop();
        sum++;
    }

    sum += st.size();

    cout << sum;
    return 0;
}