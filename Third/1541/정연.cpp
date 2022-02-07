#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string str;
    cin >> str;
 
    int result = 0;
    string tmp;
    bool minus = false;
 
    for (int i = 0; i <= str.size(); i++) {
        
        if (str[i] == '-' || str[i] == '+' || i==str.size()) {
            if (minus) {
                result -= stoi(tmp);
                tmp = "";
            }
            else {
                result += stoi(tmp);
                tmp = "";
            }
            if (str[i] == '-') {
            minus = true;
             } 
        }
        else {
            tmp += str[i];
        }
    }
    cout << result;
}
