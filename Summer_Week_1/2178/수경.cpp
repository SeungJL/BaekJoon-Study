/*
❗️ 최단 거리 문제에서 DFS를 사용하지 않는 이유는 가능한 모든 경로를 탐색하는 DFS의 특징 상 BFS에 비해 효율적이지 않기 때문이다.

void DFS(int y, int x, int cnt) {
    printf("%d %d %d\n", y, x, cnt);
    if(maze[y][x] == 0) return;
    maze[y][x] = 0;
    if (y == N - 1 && x == M - 1) {
        ans = min(ans, cnt);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (x + dx[i] < 0 || x + dx[i] > M - 1 || y + dy[i] < 0 || y + dy[i] > N - 1) continue;
        if (maze[y+dy[i]][x+dx[i]] == 0) continue;
        DFS( y + dy[i], x + dx[i], cnt + 1);
    }
}
*/

#include <bits/stdc++.h>

using namespace std;

int maze[100][100];
int cnt[100][100];

int di[4] = {0, 0, -1, 1};
int dj[4] = {1, -1, 0, 0};

int N, M;


void BFS() {
    queue<pair<int, int>> Q;
    Q.push(make_pair(0, 0));
    cnt[0][0] = 1;
    while (!Q.empty()) {
        int i = Q.front().first;
        int j = Q.front().second;
        int cur_cnt = cnt[i][j];
        Q.pop();
        maze[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            if (i + di[k] < 0 || i + di[k] > N - 1 || j + dj[k] < 0 || j + dj[k] > M - 1) continue;
            if (maze[i + di[k]][j + dj[k]] == 0) continue;
            Q.push(make_pair(i + di[k], j + dj[k]));
            maze[i + di[k]][j + dj[k]] = 0; // 써주면 메모리 초과 해결
            cnt[i + di[k]][j + dj[k]] = min(cnt[i + di[k]][j + dj[k]], cur_cnt + 1);    // 최단거리
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            maze[i][j] = str[j] - '0';
            cnt[i][j] = 20000;
        }
    }

    BFS();

    cout << cnt[N - 1][M - 1];
    return 0;
}