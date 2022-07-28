#include <iostream>
#include <queue>

using namespace std;

int N, M, cnt = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char f[51][51];
bool visited[51][51] = { false, };

void dfs(int x, int y)
{
	visited[x][y] = true;
	if (f[x][y] == '|') {
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			if (!visited[next_x][y] && f[next_x][y] == '|') {
				dfs(next_x, y);
			}
		}
	}
	if (f[x][y] == '-') {
		for (int i = 0; i < 4; i++) {
			int next_y = y + dy[i];
			if (!visited[x][next_y] && f[x][next_y] == '-') {
				dfs(x, next_y);
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> f[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;

	return 0;
}