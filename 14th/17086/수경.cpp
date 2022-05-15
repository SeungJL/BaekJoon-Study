#include <bits/stdc++.h>

using namespace std;

int N, M;
int shark[50][50];
int safe[50][50];
//동, 서, 남, 북, 남동, 북동, 남서, 북서
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

vector<pair<int, int>> V;

int BFS(int x, int y) {
    bool visited[50][50] = {0};
    queue<pair<int, pair<int, int>>> Q;
    Q.push(make_pair(x, make_pair(y, 0)));
    visited[x][y] = true;
//    printf("x=%d, y=%d\n", x, y);
    while (!Q.empty()) {
        int xx = Q.front().first;
        int yy = Q.front().second.first;
        int cnt = Q.front().second.second;
        Q.pop();
        if (shark[xx][yy] == 1) {
            return cnt;
        }

        for (int i = 0; i < 8; i++) {

            if (dx[i] + xx < 0 || dx[i] + xx > N - 1 || dy[i] + yy < 0 || dy[i] + yy > M - 1) continue;
            // printf("%d %d\n", dx[i] + xx,dy[i] + yy);
            if (visited[dx[i] + xx][dy[i] + yy] == true) continue;

            Q.push(make_pair(dx[i] + xx, make_pair(dy[i] + yy, cnt + 1)));
            visited[dx[i] + xx][dy[i] + yy] = true;
        }
    }
}

int main() {

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &shark[i][j]);
            if (shark[i][j] == 0) V.push_back(make_pair(i, j));
        }
    }


    int max_ans = 0;
    for (int i = 0; i < V.size(); i++) {
        int ans = BFS(V[i].first, V[i].second);
        max_ans = max(max_ans, ans);
    }

    printf("%d\n", max_ans);
    return 0;
}