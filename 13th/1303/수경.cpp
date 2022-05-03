#include <bits/stdc++.h>

using namespace std;

int N, M;
int war[100][100];
bool visited[100][100];
// W: true
// B: false

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 동,서,남,북

queue<int> W;
queue<int> B;

queue<pair<int, int>> Q;

void func() {

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            int flag = war[i][j];

            Q.push(make_pair(i, j));
            visited[i][j] = true;
            int size = 0;
            int x, y;
            while (!Q.empty()) {
                x = Q.front().first;
                y = Q.front().second;
                int index = war[x][y];
                Q.pop();
                size++;
                for (int k = 0; k < 4; k++) {
                    if (visited[x + dx[k]][y + dy[k]] || x + dx[k] < 0 || x + dx[k] > M - 1 || y + dy[k] < 0 ||
                        y + dy[k] > N - 1)
                        continue;
                    if (index == war[x + dx[k]][y + dy[k]]) {
                        visited[x + dx[k]][y + dy[k]] = true;
                        Q.push(make_pair(x + dx[k], y + dy[k]));
                    }
                }
            }
            if (flag == 1) W.push(size);
            else B.push(size);

        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < N; j++) {
            if (tmp[j] == 'W') war[i][j] = 1;
            else if (tmp[j] == 'B') war[i][j] = 0;
        }
    }

    func();

    int w_sum = 0, b_sum = 0;
    while (!W.empty()) {
        w_sum += W.front() * W.front();
        W.pop();
    }
    while (!B.empty()) {
        b_sum += B.front() * B.front();
        B.pop();
    }
    printf("%d %d\n", w_sum, b_sum);


    return 0;
}