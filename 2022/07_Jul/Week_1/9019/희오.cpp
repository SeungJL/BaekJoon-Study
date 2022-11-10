#include <iostream>
#include <queue>
#include <string>
#include <functional>

using namespace std;

function<int (int)> funcs[4] = { [](int n) { return (2 * n % 10000); },                     // D 
                                 [](int n) { return (n == 0) ? 9999 : n - 1; },             // S, n - 1 == 0 -> 런타임에러
                                 [](int n) { return ((n % 1000) * 10 + (n / 1000)); },      // L
                                 [](int n) { return ((n / 10) + ((n % 10 * 1000))); } };    // R
string cmd[4] = {"D", "S", "L", "R"};

void solve(int A, int B) {
    queue< pair<int, string> > Q;
    vector<bool> ch(10000, false);

    Q.push(make_pair(A, ""));
    while (!Q.empty()) {
        int n = Q.front().first;
        string str = Q.front().second;
        Q.pop();

        if (n == B) {
            cout << str << "\n";
            return;
        }

        for (int i=0; i<4; i++) {
            int new_n = funcs[i](n);
            if (ch[new_n] == false) { // pop 후에 체크 -> 시간초과
                Q.push(make_pair(new_n, str + cmd[i]));
                ch[new_n] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);

    int T;
    cin >> T;

    for (int t=0; t<T; t++) {
        int A, B;
        cin >> A >> B;

        solve(A, B);
    }
}