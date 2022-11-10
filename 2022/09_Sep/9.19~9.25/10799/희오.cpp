// 10799

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define num first 
#define loc second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    char input;
    vector<char> input_arr;
    vector<int> sticks;

    int stick_num = 1, loc = 0;
    stack<pair<int, int>> my_stack;
    while (cin >> input) {
        if (input == '(') {
            my_stack.push(make_pair(stick_num, loc));
            sticks.push_back(stick_num++);
        }
        else if (input == ')') {
            if (my_stack.top().loc + 1 == loc) {
                stick_num--;
                sticks[sticks.size()-1] = 0;
                sticks.push_back(0);
            }
            else sticks.push_back(my_stack.top().num);
            my_stack.pop();
        }
        loc++;
    }

    // for (auto e : sticks) cout << e << " ";
    // cout << endl;

    int level = 0, cnt = 0;
    stack<int> top_stick;
    top_stick.push(-1);
    for (auto it = sticks.begin(); it < sticks.end(); it++) {
        if (*it != 0) {
            if (*it > top_stick.top()) {
                level++;
                cnt++;
                top_stick.push(*it);
            }
            else if (*it == top_stick.top()) {
                level--;
                top_stick.pop();
            }
        }
        else {
            cnt += level;
            it++;
        }
    }
    
    cout << cnt << "\n";
}

