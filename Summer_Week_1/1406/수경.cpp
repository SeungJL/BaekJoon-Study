#include <bits/stdc++.h>

using namespace std;
string str;
int M;

stack<char> S1, S2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str >> M;
    for (int i = 0; i < str.size(); i++) {
        S1.push(str[i]);
    }
    for (int i = 0; i < M; i++) {
        char order, c;
        cin >> order;
        if (order == 'L') {
            if (S1.empty()) continue;
            S2.push(S1.top());
            S1.pop();
        } else if (order == 'D') {
            if (S2.empty()) continue;
            S1.push(S2.top());
            S2.pop();
        } else if (order == 'B') {
            if (S1.empty()) continue;
            S1.pop();
        } else if (order == 'P') {
            cin >> c;
            S1.push(c);
        }
    }

    while (!S1.empty()) {
        S2.push(S1.top());
        S1.pop();
    }
    while (!S2.empty()) {
        cout << S2.top();
        S2.pop();
    }

    return 0;
}