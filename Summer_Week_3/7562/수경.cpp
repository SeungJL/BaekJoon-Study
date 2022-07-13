#include <bits/stdc++.h>

using namespace std;
int graph[300][300];
int dir[8][2] = {{1,  2},
                 {2,  1},
                 {1,  -2},
                 {2,  -1},
                 {-1, 2},
                 {-2, 1},
                 {-1, -2},
                 {-2, -1}};
int n, sx, sy, fx, fy;
queue <pair<int, int>> q;

void bfs() {
    q.push({sx, sy});

    while (!q.empty()) {
        int x, y;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx >= 0 && xx < n && yy >= 0 && yy < n && !graph[xx][yy]) {
                q.push({xx, yy});
                graph[xx][yy] = graph[x][y] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> sx >> sy >> fx >> fy;
        graph[sx][sy] = 1;
        bfs();
        cout << graph[fx][fy] - 1 << '\n';
        memset(graph, 0, sizeof(graph));

    }

    return 0;
}