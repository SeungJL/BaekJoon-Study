#include <iostream>
#include <stack>
using namespace std;

int dp[100001] = { 0, };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    stack<int> s;
    int ans = 0;
    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;

        if(y == 0) {
            while(!s.empty()) {
                s.pop();
                ans++;
            }
        } else {
            if(!s.empty()) {
                if(s.top() < y) {
                    s.push(y);
                } else if (s.top() > y) {
                    while(!s.empty() && s.top() >= y) {
                        if(s.top() != y) {
                            ans++;
                        }
                        s.pop();
                    } 
                    s.push(y);
                }
            } else {
                s.push(y);
            }
        }
    }

    while(!s.empty()) {
        s.pop();
        ans++;
    }


    cout << ans;
}