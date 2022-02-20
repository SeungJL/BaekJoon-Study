#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define N 51
using namespace std;

int map[N][N];
bool visited[N][N];
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };

void DFS(int y, int x, int h, int w) {
	visited[y][x] = true;
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
		else if (map[ny][nx] == 1 && !visited[ny][nx]) DFS(ny, nx, h, w);
	}
}

int main(void) {
	//freopen("input.txt", "rt", stdin);
	
	int w, h;
	while(scanf("%d%d", &w, &h) && !(w==0 && h==0)) {
		fill(&visited[0][0], &visited[N-1][N-1], false);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		int ans = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					DFS(i, j, h, w);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}