#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>

#define N 5
using namespace std;

int arr[N][N];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
set<int> s;

void DFS(int y, int x, int n, int len) {
	if (len == 6) {
		s.insert(n);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
			DFS(ny, nx, n * 10 + arr[ny][nx], len + 1);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "rt", stdin);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	} // 입력

	/* 모든 좌표의 DFS 경로 탐색 */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			DFS(i, j, arr[i][j], 1);
		}
	}

	cout << s.size();

	return 0;
}