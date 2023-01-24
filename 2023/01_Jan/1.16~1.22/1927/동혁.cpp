#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
long long t, x;
priority_queue<long long, vector<long long>, greater<long long>> pQ;
int main() {
    fastio;
    cin >> t;
    for(int i = 0; i < t; i++) {
        long long temp;
        cin >> temp;
        if(temp == 0) {
            if(pQ.empty()) {
                cout << 0 << '\n';
            } else {
                cout << pQ.top() << '\n';
                pQ.pop();
            }
        } else {
            pQ.push(temp);
        }
    }

    return 0;
}