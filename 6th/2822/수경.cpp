#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> V;

bool compareSecond(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

bool compareFirst(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    for (int i = 0; i < 8; i++) {
        int tmp;
        cin >> tmp;
        V.push_back(make_pair(i + 1, tmp));
    }
    sort(V.begin(), V.end(), compareSecond);
    sort(V.begin(), V.begin() + 5, compareFirst);

    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += V[i].second;
    }
    cout << sum << '\n';
    for (int i = 0; i < 5; i++) cout << V[i].first << " ";


    return 0;
}