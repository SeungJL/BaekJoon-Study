#include <bits/stdc++.h>

using namespace std;



int main(){

    string str;
    cin >> str;

    vector<string> V;


    for(int i=1;i<=str.length();i++){
        for(int j=i+1;j<str.length();j++){
            string a = str.substr(0, i);
            string b = str.substr(i, j-i);
            string c = str.substr(j, str.length()-j);
            std::reverse(a.begin(), a.end());
            std::reverse(b.begin(), b.end());
            std::reverse(c.begin(), c.end());
            string d = a+b+c;
            V.push_back(d);
        }
    }
    sort(V.begin(), V.end());
    cout << V[0];

    return 0;
}