#include <bits/stdc++.h>

using namespace std;

string fibo[10001];

string addNum(string a, string b) {
    string ans(a.size(), '0');
    int carry = 0;

    for (int i = 0; i < a.size(); i++) {
        int num = carry;
        num += a[a.size() - i - 1] - '0';
        if (i < b.size()) num += b[b.size() - i - 1] - '0';
        if (num >= 10) {
            carry = 1;
            num -= 10;
        } else carry = 0;
        ans[a.size() - 1 - i] += num;
        //cout << "ans[] = "<< ans[a.size()-1-i] <<"\n";


    }
    if (carry == 1) ans = "1" + ans;
    return ans;
}

int main() {
//    string a, b;
//    cin >> a >> b;
//    cout << addNum(a, b) << "\n";
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    fibo[0] = '0';
    fibo[1] = '1';
    for (int i = 2; i <= n; i++) {
        fibo[i] = addNum(fibo[i - 1], fibo[i - 2]);
//        cout << fibo[i] << "\n";
    }
    cout << fibo[n];
    return 0;
}