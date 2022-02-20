#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    int N;
    cin >> N;
    cin.get();
    cin >> str;
    vector<double> num;
    for (int i = 0; i < N; i++) {
        double tmp;
        scanf("%lf", &tmp);
        num.push_back(tmp);
    }

    stack<double> S;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            S.push(num[str[i] - 'A']);
        } else {
            if (str[i] == '+') {
                double a = S.top();
                S.pop();
                double b = S.top();
                S.pop();
                S.push(b + a);
            } else if (str[i] == '-') {
                double a = S.top();
                S.pop();
                double b = S.top();
                S.pop();
                S.push(b - a);
            } else if (str[i] == '*') {
                double a = S.top();
                S.pop();
                double b = S.top();
                S.pop();
                S.push(b * a);
            } else if (str[i] == '/') {
                double a = S.top();
                S.pop();
                double b = S.top();
                S.pop();
                S.push(b / a);
            }
        }
    }
    printf("%.2lf", S.top());
    return 0;
}