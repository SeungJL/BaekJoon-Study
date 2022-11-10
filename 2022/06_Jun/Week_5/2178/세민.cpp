#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
char map[101][101] = {};	//미로
bool visit[101][101] = {false, };	//방문 여부
int check[101][101] = {};	//시작점으로부터의 거리
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void BFS(int x, int y)	//너비우선탐색
{
	visit[x][y] = true;	//방문
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny < M && nx < N && ny >= 0) {
				if (map[nx][ny] == '1' && !visit[nx][ny]) {	//이동할 수 있고 방문한 적이 없는 경우
					check[nx][ny] = check[x][y] + 1;
					visit[nx][ny] = true;	//방문
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {	//미로가 붙어서 입력으로 주어짐
		cin >> map[i];
	}

	BFS(0, 0);	//(0,0)에서 출발하여 (N-1, M-1)의 위치로 이동

	cout << check[N - 1][M - 1] + 1;	//(N-1, M-1) 도착위치, 도착위치도 포함하여 칸 세기
	return 0;
}