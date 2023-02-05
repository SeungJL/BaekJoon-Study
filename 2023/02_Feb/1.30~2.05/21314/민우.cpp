#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string str;
    cin >> str;
    stack<char> s;

    string max_ans = "";
    for(int i=0; i<str.length(); i++) {
        if(str[i] == 'K') {
            string temp = "5";
            while(!s.empty()) {
                temp += "0";
                s.pop();
            }
            max_ans += temp;
        } else if(str[i] == 'M') {
            s.push('M');
        }
    }
    
    while(!s.empty()) {
        s.pop();
        max_ans += "1";
    }
    // ---------------------

    string min_ans = "";
    for(int i=0; i<str.length(); i++) {
        if(str[i] == 'K') {
            if(!s.empty()) {
                min_ans += "1";
                s.pop();

                while(!s.empty()) {
                    min_ans += "0";
                    s.pop();
                } 
            }
            min_ans += "5";
        } else if(str[i] == 'M') {
            s.push('M');
        }
    }

    if(!s.empty()) {
        min_ans += "1";
        s.pop();

        while(!s.empty()) {
            min_ans += "0";
            s.pop();
        } 
    }


    cout << max_ans << "\n" << min_ans;
}