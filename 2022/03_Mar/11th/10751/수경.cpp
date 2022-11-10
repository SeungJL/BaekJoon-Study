#include <bits/stdc++.h>

using namespace std;

unordered_set<int> c_index;
unordered_set<int> o_index;
unordered_set<int> w_index;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string str;
    cin >> str;
    long long c = 0;
    long long co = 0;
    long long cow = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'C') c++;
        if (str[i] == 'O') co += c;
        if (str[i] == 'W') cow += co;
    }
    cout << cow;


    return 0;
}
/*
 * CWOW -> 1
 * CCOW -> 2
 * CWOWOW -> 3
 * CCOOWW -> 8
 * COOWWW -> 6
 */