#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int l, x_0, y_0, x_1, y_1;
int board[300][300];
bool visit[300][300] = { false, };
int dx[8] = { 1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = { 2, -2, 1, -1, 2, -2, 1, -1 };

void bfs(int x, int y, int x2, int y2)
{
	int d = 0;
	visit[x][y] = true;
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		if (x == x2 && y == y2) {
			d = board[x][y];
		}
		q.pop();

		for (int i = 0; i < 8; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			
			if (next_x >= 0 && next_y < l && next_x < l && next_y >= 0) {
				if (!visit[next_x][next_y]) {
					visit[next_x][next_y] = true;
					board[next_x][next_y] = board[x][y] + 1;
					q.push(make_pair(next_x, next_y));
				}
			}
		}
	}
	cout << d << '\n';
}

int main(void)
{
	int T;
	cin >> T;
	while (T--) {
		cin >> l >> x_0 >> y_0 >> x_1 >> y_1;
		memset(board, false, sizeof(board));
		memset(visit, false, sizeof(visit));
		bfs(x_0, y_0, x_1, y_1);
	}

	return 0;
}