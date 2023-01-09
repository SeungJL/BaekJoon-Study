#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void split(deque<int> &v, string str) {
    istringstream iss(str);            
    string buffer;                     
 

    while (getline(iss, buffer, ',')) {
        v.push_back(stoi(buffer));
    }
}

void makeVector(deque<int> &v, string arr) {
    split(v, arr.substr(1, arr.length() - 2));
}
void commandR(deque<int> &v) {
    reverse(v.begin(), v.end());
}

bool commandD(deque<int> &v, bool reverse) {
    if(v.empty()) {
        return false;
    }

    if(reverse) {
        v.pop_back();
        return true;
    }

    v.pop_front();
    return true;
}

string eraseDoubleR(string cmd) {
    string newString = "";
    stack<char> st;
    
    for(char ch : cmd) {
        if(st.empty()) {
            st.push(ch);
            continue;
        }

        if(st.top() == 'R' && ch == 'R') {
            st.pop();
            continue;
        }

        st.push(ch);
    }

    while(!st.empty()) {
        newString += st.top();
        st.pop();
    }

    reverse(newString.begin(), newString.end());
    return newString;
}
int main() {
    fastio;
    int testNum;


    cin >> testNum;
    while(testNum--) {

        string cmd;
        cin >> cmd;

        int cnt;
        cin >> cnt;

        string arr;
        cin >> arr;

        bool success = true;
        bool reverse = false;

        deque<int> v;
        makeVector(v, arr);

        cmd = eraseDoubleR(cmd);

        for(char ch : cmd) {
            if(ch == 'R') {
                reverse = reverse ^ 1;
            } else {
                if(!commandD(v, reverse)) {
                    cout << "error" << endl;
                    success = false;
                    break;
                }
            }
        }

        if(!success) {
            continue;
        }

        if(reverse) {
            commandR(v);
        }

        string result = "[";
        for(int num : v) {
            result += to_string(num);
            result += ",";
        }

        if(result.length() != 1) {
            result = result.substr(0, result.length() - 1);
        }

        result += "]";
        cout << result << endl;
    }

    return 0;
}