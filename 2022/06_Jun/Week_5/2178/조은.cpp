#include <stdio.h>
#include <queue>
#define MAX 101
using namespace std;

int N, M;
int maze[MAX][MAX];
int dist[MAX][MAX]; // -1은 방문X를 의미
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void bfs(int y, int x) {
	queue<pair<int,int>> q;
	q.push({y,x});
	dist[y][x] = 1;

	while(!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for(int dir=0; dir<4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			if(ny<1 || nx<1 || ny>N || nx>M) continue;
			if((dist[ny][nx] >= 1) || (maze[ny][nx] != 1)) continue;
			q.push({ny,nx});
			dist[ny][nx] = dist[cy][cx] + 1;
		}
	}
	return;
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}

	fill(&dist[0][0], &dist[MAX-1][MAX-1], -1);

	bfs(1, 1);
	printf("%d", dist[N][M]);

	return 0;
}