#include <bits/stdc++.h>

using namespace std;

vector<pair<long long int, long long int>> meeting;

bool compare(pair<long long int, long long int> A, pair<long long int, long long int> B) {
    if (A.second == B.second) return A.first < B.first;
    return A.second < B.second;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        long long int start, end;
        cin >> start >> end;
        meeting.push_back({start, end});
    }
    sort(meeting.begin(), meeting.end(), compare);

    long long int cur_time = meeting[0].second;
    int cnt = 1;
    for (int i = 1; i < N; i++) {
        if (cur_time > meeting[i].first) continue;
        cur_time = meeting[i].second;
        cnt++;
    }

    cout << cnt;

    return 0;
}