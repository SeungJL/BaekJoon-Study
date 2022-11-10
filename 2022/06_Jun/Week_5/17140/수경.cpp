#include <bits/stdc++.h>

using namespace std;
int A[100][100];


int r, c, K;
int row, column;
vector<vector<pair<int, int>>> V;

bool compare(pair<int, int> A, pair<int, int> B) {
    if (A.second == B.second) return A.first < B.first;
    return A.second < B.second;
}

int R() {
    vector<int> k_loc;
    int max_row_cnt = 0;
    for (int i = 0; i < column; i++) {
        vector<int> num(101);
        for (int j = 0; j < row; j++) {
            num[A[i][j]]++;
        }
        vector<pair<int, int>> tmp;
        for (int j = 1; j <= 100; j++) {
            if (num[j] != 0) tmp.push_back(make_pair(j, num[j]));
        }
        V.push_back(tmp);
        sort(tmp.begin(), tmp.end(), compare);
        max_row_cnt = max(max_row_cnt, (int) tmp.size() * 2);

        int k = 0;
        for (int j = 0; j < tmp.size(); j++) {
            A[i][k] = tmp[j].first;
            A[i][k + 1] = tmp[j].second;
            k += 2;
        }
        k_loc.push_back(tmp.size() * 2);
    }

    for (int i = 0; i < column; i++) {
        int k = k_loc[i];
        for (int j = k; j < max_row_cnt; j++) {
            A[i][j] = 0;
        }
    }
    return max_row_cnt;
}

int C() {
    vector<int> k_loc;
    int max_column_cnt = 0;
    for (int i = 0; i < row; i++) {
        vector<int> num(101);
        for (int j = 0; j < column; j++) {
            num[A[j][i]]++;
        }
        vector<pair<int, int>> tmp;
        for (int j = 1; j <= 100; j++) {
            if (num[j] != 0) tmp.push_back(make_pair(j, num[j]));
        }
        V.push_back(tmp);
        sort(tmp.begin(), tmp.end(), compare);
        max_column_cnt = max(max_column_cnt, (int) tmp.size() * 2);
        int k = 0;
        for (int j = 0; j < tmp.size(); j++) {
            A[k][i] = tmp[j].first;
            A[k + 1][i] = tmp[j].second;
            k += 2;
        }
        k_loc.push_back(tmp.size() * 2);
    }


    for (int i = 0; i < row; i++) {
        int k = k_loc[i];
        for (int j = k; j < max_column_cnt; j++) {
            A[j][i] = 0;
        }
    }

    return max_column_cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> K;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }
    int time = 0;

    column = 3;
    row = 3;

    while (time <= 100) {
        if (A[r - 1][c - 1] == K) break;
        if (column >= row) row = R();
        else column = C();
        time++;
    }
    if (time == 101) time = -1;
    cout << time;

    return 0;
}