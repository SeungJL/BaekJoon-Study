#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int T;
    cin >> T;
    while (T--) {
        string num;
        cin >> num;
        string a = "", b = "";
        for (int i = 2; i < num.size(); i++) {
            if (num[i] == '(') {
                i++;
                while (num[i] != ')') {
                    b += num[i];
                    i++;
                }
                break;
            }
            a += num[i];

        }

        int a_num = 0, b_num = 0;
        if(a != "") a_num = stoi(a);
        if(b != "")b_num = stoi(b);

        int ten = 1;
        for (int i = 0; i < a.size() + b.size(); i++) ten *= 10;


        int ten1 = 1;
        for (int i = 0; i < a.size(); i++) ten1 *= 10;
        int ten2 = 1;
        for (int i = 0; i < b.size(); i++) ten2 *= 10;
        if (b == "") {
            //이부분~~~~~~~ 0.4
            if(ten%a_num ==0 )cout << ten % a_num+1 << '/' << ten / a_num << "\n";
            else cout << ten % a_num << '/' << ten / a_num << "\n";
        }
        else cout << ten2 % b_num + ten / b_num / ten1 * a_num << '/' << ten / b_num << "\n";


    }
    return 0;
}