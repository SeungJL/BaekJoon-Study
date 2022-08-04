#include <bits/stdc++.h>

using namespace std;

/*
 * I: 1
 * IV: 4
 * V: 5
 * IX: 9
 * X: 10
 * XL: 40
 * L: 50
 * XC: 90
 * C: 100
 * CD: 400
 * D: 500
 * CM: 900
 * M: 1000
 */

vector<pair<string, int>> roma;

void initialize() {
    roma.push_back({"I", 1});
    roma.push_back({"IV", 4});
    roma.push_back({"V", 5});
    roma.push_back({"IX", 9});
    roma.push_back({"X", 10});
    roma.push_back({"XL", 40});
    roma.push_back({"L", 50});
    roma.push_back({"XC", 90});
    roma.push_back({"C", 100});
    roma.push_back({"CD", 400});
    roma.push_back({"D", 500});
    roma.push_back({"CM", 900});
    roma.push_back({"M", 1000});
}

int romanToArabic(string str) {
    for (int i = 0; i < roma.size(); i++) {
        if (roma[i].first == str) return roma[i].second;
    }
    return -1;
}

int convertRomanToArabic(string str) {
    int num = 0;
    for (int i = 0; i < str.size(); i++) {
        int tmp = romanToArabic(str.substr(i, 2));
        if (tmp != -1) {
            num += tmp;
            i++;
        } else {
            num += romanToArabic(str.substr(i, 1));
        }
    }
    return num;
}

string convertArabicToRoman(int num) {
    string resultStr = "";
    for (int i = roma.size() - 1; i >= 0; i--) {
        while (num - roma[i].second >= 0) {
            num -= roma[i].second;
            resultStr += roma[i].first;
        }
    }
    return resultStr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    initialize();

    string A, B;
    cin >> A >> B;
    int ans = convertRomanToArabic(A) + convertRomanToArabic(B);
    string ansString = convertArabicToRoman(ans);
    cout << ans << "\n" << ansString;


    return 0;
}