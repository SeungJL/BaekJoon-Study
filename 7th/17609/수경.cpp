#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != str[str.size() - 1 - i]) return false;
    }
    return true;
}

int solve(string str) {
    int cnt = 0;
    int i = 0, j = str.size() - 1;

    while (i <= j) {
        if (str[i] != str[j]) {

            if (cnt == 0) {
                cnt++;
                if (str[i] == str[j - 1] && str[i + 1] == str[j]) {
                    if (isPalindrome(str.substr(i, j - i))) return 1;
                    if (isPalindrome(str.substr(i + 1, j - i))) return 1;
                } else if (str[i] == str[j - 1]) j--;
                else if (str[i + 1] == str[j]) i++;
                else return 2;
            } else return 2;
        }
        i++;
        j--;
    }
    if (cnt == 0) return 0;
    else return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        cout << solve(str) << "\n";
    }
    return 0;
}


/* abbab
 * babba
 *
 * aabcbcaa
 * ababbabaa
 */