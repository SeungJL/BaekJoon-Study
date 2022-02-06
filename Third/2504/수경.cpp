#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    stack<char> S;

    cin >> str;
    int result = 0;
    int temp = 1;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            temp *= 2;
            S.push(str[i]);
        } else if (str[i] == '[') {
            temp *= 3;
            S.push(str[i]);
        } else if (str[i] == ')') {
            if (S.empty() || S.top() != '(') {
                result = 0;
                break;
            } else if (str[i - 1] == '(') {
                result += temp;
                temp /= 2;
                S.pop();
            } else {
                temp /= 2;
                S.pop();
            }
        } else if (str[i] == ']') {
            if (S.empty() || S.top() != '[') {
                result = 0;
                break;
            } else if (str[i - 1] == '[') {
                result += temp;
                temp /= 3;
                S.pop();
            } else {
                temp /= 3;
                S.pop();
            }
        }
    }
    if (!S.empty()) result = 0;
    cout << result;

    return 0;
}