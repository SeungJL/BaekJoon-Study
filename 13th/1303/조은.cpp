#include <iostream>
#include <queue>
using namespace std;

int N, M;
char fight[101][101];
bool visited[101][101] = { false, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt = 0;

void bfs(int y, int x, char team) {

	int power = 0;
	queue<pair<int, int>> q; // {y,x}
	q.push( {y,x} );
	visited[y][x] = true;

	while(!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for(int i=0; i<4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(nx<1 || ny<1 || nx>N || ny>M) continue;
			if( (fight[ny][nx] == team) && !visited[ny][nx] ) {
				cnt++;
				q.push( {ny,nx} );
				visited[ny][nx] = true;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for(int i=1; i<=M; i++) { // 세로
		for(int j=1; j<=N; j++) { // 가로
			cin >> fight[i][j];
		}
	}

	int w=0, b=0;

	for(int i=1; i<=M; i++) {
		for(int j=1; j<=N; j++) {
			if(fight[i][j] == 'W' && !visited[i][j]) {
				cnt = 1;
				bfs(i,j,'W');
				w += cnt*cnt;
			}
		}
	}

	fill(&visited[0][0], &visited[100][100], false);
	cnt=0;
	for(int i=1; i<=M; i++) {
		for(int j=1; j<=N; j++) {
			if(fight[i][j] == 'B' && !visited[i][j]) {
				cnt = 1;
				bfs(i,j,'B');
				b += cnt*cnt;
			}
		}
	}

	cout << w << ' ' << b;

	return 0;
}