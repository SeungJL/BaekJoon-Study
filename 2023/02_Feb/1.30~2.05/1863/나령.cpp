#include <iostream>
#include <stack>
using namespace std;
int n, t, ans;
int m[55555];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t >> m[i];
    stack<int> s;
    for (int i = 0; i < n; i++) {
        if (m[i] != 0) { 
            bool exist = false;
            while (!s.empty()) {
                if (s.top() == m[i]) { 
                    exist = true;
                    break;
                }
                if (s.top() < m[i]) {
                    break;
                }
                s.pop();
            }
            if (exist) continue;
            else { 
                s.push(m[i]);
                ans++;
            }
        }
        else while (!s.empty()) s.pop();
    }    
    cout << ans;
    return 0;
}