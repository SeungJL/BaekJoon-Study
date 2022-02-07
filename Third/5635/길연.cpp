// 백준 5635번 생일

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int main(int argc, const char* argv[]) {

    int num;
    string name;
    vector<pair<pair<int, int>, pair<int, string>>> vec;

    cin >> num;

 
    for (int i = 1; i <= num; i++) {

        int day, month, year;
        cin >> name >> day >> month >> year;
        vec.push_back({ {year, month},{day, name} });
    }

    sort(vec.begin(), vec.end());
    cout << vec[vec.size() - 1].second.second << "\n" << vec[0].second.second;

    return 0;
}
