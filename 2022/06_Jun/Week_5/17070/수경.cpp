#include <bits/stdc++.h>

using namespace std;


// direct 0:가로, 1:세로, 2:대각
int di[3] = {0, 1, 1};
int dj[3] = {1, 0, 1};
int dir[3] = {0, 1, 2};
int N;
int cnt;
int house[17][17];

void DFS(int i, int j, int direct) {
    if (i == N && j == N) {
        cnt++;
        return;
    }
    if (direct == 0) {
        if (i + di[0] >= 1 && i + di[0] <= N && j + dj[0] >= 1 && j + dj[0] <= N) {
            if (house[i + di[0]][j + dj[0]] != 1) DFS(i + di[0], j + dj[0], dir[0]);
        }
        if (i + di[2] >= 1 && i + di[2] <= N && j + dj[2] >= 1 && j + dj[2] <= N) {
            if (house[i + di[0]][j + dj[0]] != 1 && house[i + di[1]][j + dj[1]] != 1 &&
                house[i + di[2]][j + dj[2]] != 1)
                DFS(i + di[2], j + dj[2], dir[2]);
        }
    } else if (direct == 1) {
        if (i + di[1] >= 1 && i + di[1] <= N && j + dj[1] >= 1 && j + dj[1] <= N) {
            if (house[i + di[1]][j + dj[1]] != 1) DFS(i + di[1], j + dj[1], dir[1]);
        }
        if (i + di[2] >= 1 && i + di[2] <= N && j + dj[2] >= 1 && j + dj[2] <= N) {
            if (house[i + di[0]][j + dj[0]] != 1 && house[i + di[1]][j + dj[1]] != 1 &&
                house[i + di[2]][j + dj[2]] != 1)
                DFS(i + di[2], j + dj[2], dir[2]);
        }
    } else if (direct == 2) {
        if (i + di[0] >= 1 && i + di[0] <= N && j + dj[0] >= 1 && j + dj[0] <= N) {
            if (house[i + di[0]][j + dj[0]] != 1) DFS(i + di[0], j + dj[0], dir[0]);
        }
        if (i + di[1] >= 1 && i + di[1] <= N && j + dj[1] >= 1 && j + dj[1] <= N) {
            if (house[i + di[1]][j + dj[1]] != 1) DFS(i + di[1], j + dj[1], dir[1]);
        }
        if (i + di[2] >= 1 && i + di[2] <= N && j + dj[2] >= 1 && j + dj[2] <= N) {
            if (house[i + di[0]][j + dj[0]] != 1 && house[i + di[1]][j + dj[1]] != 1 &&
                house[i + di[2]][j + dj[2]] != 1)
                DFS(i + di[2], j + dj[2], dir[2]);
        }
    }


}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cnt = 0;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> house[i][j];
        }
    }

    DFS(1, 2, 0);
    cout << cnt;
    return 0;
}