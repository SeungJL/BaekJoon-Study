#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        unordered_map<string, int> um;
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            string name, category;
            cin >> name >> category;
            um[category]++;
        }
        int total = 1;
        for (auto elem: um) {
            total *= (elem.second + 1);
        }
        cout << total - 1 << '\n';
    }


    return 0;
}