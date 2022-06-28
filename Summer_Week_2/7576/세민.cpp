#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int M, N;
int arr[1000][1000];	//토마토의 정보를 저장하는 배열
bool visit[1000][1000] = { false, };	//방문 여부를 저장하는 배열
int path[1000][1000];	//방문 일자를 저장하는 배열
queue<pair<int, int>> q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs()	//너비 우선 탐색
{
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (arr[nx][ny] == 0 && !visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push(make_pair(nx, ny));
					path[nx][ny] = path[x][y] + 1;
				}
			}
		}
	}
}

int main(void)
{
	int ans = -1;
	cin >> N >> M;	//가로, 세로
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	/*익은 토마토를 찾아 너비 우선 탐색의 출발점으로 큐에 push*/
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}
	
	bfs();

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0 && path[i][j] == 0) {	//토마토가 익지 못하는 경우(익지 못하는 토마토가 존재하지만 방문 한 적이 없음)
				cout << -1;
				return 0;
			}
		}
	}

	/*방문 일자 배열 중 최댓값 출력*/
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			ans = max(ans, path[i][j]);
		}
	}

	cout << ans;
}