#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;
stack<int> stick;
vector<pair<int, int>> laser;
vector<pair<int, int>> sticks;

int main() {
    string s;
    cin >> s;

    bool jump = false;
    for(int i=0; i<s.length(); i++) {

        if(jump) {
            jump = false;
            continue;
        }

        if(s[i] == '(' && i != s.length()) {
          if(s[i+1] == ')') {
            laser.push_back({ i, i+1 });
            jump = true;
            // cout << "laser! " << i << " " << i + 1 << "\n";
          } else {
            stick.push(i);
          }
        } else {
            sticks.push_back({ stick.top(), i });
            stick.pop();
        }
    }

    // 0 1 | 5 6 | 7 8 | 11 12 | 14 15 | 19 20 
    // 4 9 | 10 13 | 3 16 | 2 17 | 18 21 

    int answer = 0;
    for(int i=0; i<sticks.size(); i++) {
        // cout << sticks[i].first << "  " << sticks[i].second << " | ";
        
        int piece = 0;
        int stick_start = sticks[i].first;
        int stick_end = sticks[i].second;

        for(int i=0; i<laser.size(); i++) {
            // cout << laser[i].first << " " << laser[i].second << " | ";

            int laser_start = laser[i].first;
            int laser_end = laser[i].second;
            if(stick_start < laser_start && stick_end > laser_end) {
                piece++;
            }
        }
        answer += piece + 1;
    }
    cout << answer;

}