#include <bits/stdc++.h>

using namespace std;


long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;

        //정수 부분과 소수 부분으로 split
        long long a = 0, b = 0;
        long long a_len = 0, b_len = 0;
        for (int i = 2; i < str.size(); i++) {
            if (str[i] == '(') {
                i++;
                while (str[i] != ')') {
                    b = b * 10 + str[i] - '0';
                    b_len++;
                    i++;
                }
                break;
            }
            a = a * 10 + str[i] - '0';
            a_len++;
        }

        //분자
        long long up;
        long long ten = 1;
        for (int i = 0; i < b_len; i++) ten *= 10;

        if (b == 0) up = a * ten + b;
        else up = (a * ten + b) - a;


        //분모
        long long down;
        if (b_len == 0) down = 1;
        else down = 0;
        for (int i = 0; i < b_len; i++) down = down * 10 + 9;
        for (int i = 0; i < a_len; i++) down = down * 10;

        long long gcd = GCD(up, down);
        cout << up / gcd << "/" << down / gcd << "\n";

    }
    return 0;
}
