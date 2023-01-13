#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<int> v;

vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string tmp;
 
    while (getline(ss, tmp, delimiter)) result.push_back(tmp);
 
    return result;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        string cmd;
        cin >> cmd;

        int n;
        cin >> n;

        string s;
        cin >> s;

        // [1,2,3,4] -> 1,2,3,4
        s = s.substr(0, s.length() - 1);
        s = s.substr(1, s.length());

        // 1,2,3,4 -> 1 2 3 4 
        vector <string> result = split(s, ',');
        for(auto &r : result) {
            // '1' -> 1
            v.push_back(stoi(r));
        }

        int start = 0;
        int end = v.size() - 1;
        int len = v.size();
        bool error = false;

        for(int i=0; i<cmd.length(); i++) {
            // cout << "len: " << len << "\n";
            if(cmd[i] == 'R') {
                int temp = end;
                end = start;
                start = temp;
            } else if (cmd[i] == 'D') {
                if(len == 0) {
                    error = true;
                    break;
                }
                len--;
                if(start > end) { // 역방향
                    start--;
                } else { // 정방향
                    start++;
                }
            }
        }

        if(error) {
            cout << "error\n";
        } else if(len ==0) {
            cout << "[]\n";
        } 
         else if(start > end) {
            cout << "[";
            for(int i=start; i >= end; i--) {
                cout << v[i];
                if(i != end) {
                    cout << ",";
                }
            }
            cout << "]\n";
        } else if(start <= end) {
            cout << "[";
            for(int i=start; i<= end; i++) {
                cout << v[i];
                if(i != end) {
                    cout << ",";
                }
            }
            cout << "]\n";
        }

        v.clear();
    }
}