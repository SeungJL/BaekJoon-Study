#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    vector<int> num;
    vector<char> op;
    int tmp = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            tmp *= 10;
            tmp += str[i] - '0';
            if (str[i + 1] < '0' || str[i + 1] > '9') {
                num.push_back(tmp);
                tmp = 0;
                if (str[i + 1] == '+' || str[i + 1] == '-') {
                    op.push_back(str[i + 1]);
                    i++;
                }
            }
        }
    }

    int result = num[0];
    for (int i = 0; i < op.size(); i++) {
        if (op[i] == '+') result += num[i + 1];
        if (op[i] == '-') {
            int j = i + 1;
            tmp = num[j];
            for (; j < op.size(); j++) {
                if (op[j] == '+') tmp += num[j + 1];
                else break;
            }
            i = j - 1;
            result -= tmp;
        }
    }

    cout << result;

    return 0;
}