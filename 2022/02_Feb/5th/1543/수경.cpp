#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a.substr(i, b.size()) == b) {
            i += b.size() - 1;
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}