#include <bits/stdc++.h>

using namespace std;

int getSum(string str) {
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') sum += str[i] - '0';
    }
    return sum;
}

bool compare(string a, string b) {
    if (a.length() == b.length()) {
        if (getSum(a) == getSum(b)) return a < b;
        return getSum(a) < getSum(b);
    }
    return a.length() < b.length();
}

int main() {
    int N;
    cin >> N;
    vector <string> number;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        number.push_back(tmp);
    }
    sort(number.begin(), number.end(), compare);
    for (int i = 0; i < N; i++) {
        cout << number[i] << "\n";
    }

    return 0;
}