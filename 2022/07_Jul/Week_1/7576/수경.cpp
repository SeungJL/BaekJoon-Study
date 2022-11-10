#include <bits/stdc++.h>

using namespace std;

int M, N;
int box[1000][1000];
int day[1000][1000];

int di[4] = {0, 0, -1, 1};
int dj[4] = {1, -1, 0, 0};
int cnt;
queue<pair<int, int>> tomatoes;


int BFS() {
    int ans = 0;
    while (!tomatoes.empty()) {
        int i = tomatoes.front().first;
        int j = tomatoes.front().second;
        tomatoes.pop();
        for (int k = 0; k < 4; k++) {
            int new_i = i + di[k];
            int new_j = j + dj[k];
            if (new_i < 0 || new_i > N - 1 || new_j < 0 || new_j > M - 1) continue;
            if (box[new_i][new_j] != 0) continue;
            box[new_i][new_j] = 1;
            tomatoes.push(make_pair(new_i, new_j));
            cnt--;
            day[new_i][new_j] = day[i][j] + 1;
            ans = day[new_i][new_j];
        }
    }
    if (cnt > 0) return -1;
    else return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) tomatoes.push(make_pair(i, j));
            else if (box[i][j] == 0) cnt++;
        }
    }
    int ans = BFS();
    if (ans == -1) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}