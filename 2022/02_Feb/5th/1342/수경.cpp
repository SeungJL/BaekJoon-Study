#include <bits/stdc++.h>

using namespace std;

string str;
int alphabet[26];
int ans;

/*
 * aabbbaa
 * a = 4, b = 3
 *
 *
 */
void DFS(string prev, int len) {
    if (str.size() == len) {
        //cout << prev << "\n";
        ans++;
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] > 0 && i != prev[prev.size() - 1] - 'a') {
            alphabet[i]--;
            DFS(prev + (char) ('a' + i), len + 1);
            alphabet[i]++;
        }
    }
}

int main() {

    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        alphabet[str[i] - 'a']++;
    }
    DFS("", 0);
    cout << ans;
    return 0;
}
/*
 *
 * a = 4
 * b = 3
 *
 * aabbbaa
 * abababa
 *
 *
 * ab
 * ab
 * ba
 *
 * aaab
 * 0
 *
 * abcdefghij
 * 10*9*8*7...
 */