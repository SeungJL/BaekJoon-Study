#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int N, M;
int shark[51][51];
int dist[51][51]; // -1이면 방문하지 않았음을 의미
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };

void bfs(int y, int x) {
	queue<pair<int,int>> q;
	q.push({y,x});
	dist[y][x] = 0;
	int cnt = 0;
	while(!q.empty()) {
		pair<int,int> cur = q.front();
		q.pop();
		if(shark[cur.X][cur.Y]) return;
		for(int i=0; i<8; i++) {
			int ny = cur.Y + dy[i];
			int nx = cur.X + dx[i];
			if(ny<1 || ny>N-1 || nx<1 || nx>M) continue;
			if(dist[ny][nx] >= 0) continue;
			q.push( {ny,nx} );
			dist[ny][nx] = dist[cur.Y][cur.X] + 1;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for(int i=1; i<=N; i++) 
		for(int j=1; j<=M; j++)
			cin >> shark[i][j];
	
	fill(&dist[0][0], &dist[50][50], -1);

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if(shark[i][j] == 0)
				if(dist[i][j] == -1)
					 bfs(i,j);
		}
	}

	cout << *max_element(&dist[0][0], &dist[50][50]);

	return 0;
}