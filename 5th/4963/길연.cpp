// 백준 4963번 섬의 개수

#include <iostream>


using namespace std;
// 상하좌우 대각선4방향 닿으면 같은 섬. 총 섬개수 찾기
int map[50][50];
bool visit[50][50];
// 상 우 하 좌 우상 우하 좌하 좌상
int dx[] = { 0, 1, 0, -1, 1,1,-1,-1 };
int dy[] = { 1,0,-1,0,1,-1,-1,1 };
int w, h;

void dfs(int x, int y, int cnt) {
	visit[y][x] = 1;

	for (int i = 0; i < 8; i++) { // 이동
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= w || ny >= h)
			continue;
		if (map[ny][nx] == 1 && visit[ny][nx] == 0) {
			dfs(ny, nx, cnt);
		}
	}
}

void reset() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			map[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}

int main() {
	int w, h;


	while (true) { // 입력 0 0 되면 종료되게끔
		cin >> w >> h;
		if ((w == 0) && (h == 0))
			break;

		reset(); // 맵, 방문 초기화

		for (int i = 0; i < h; i++) { // h개 줄단위 입력
			for (int j = 0; j < w; j++) { // w개 행단위 입력
				cin >> map[i][j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < h; i++) { // 맵 탐색
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && visit[i][j] == 0)
					dfs(i, j, ++cnt);
			}
		}


		cout << cnt << endl;
	}


	return 0;
}
