#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N;
int INF = 10000000;
int arr[125][125];
int d[125][125];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void dijkstra() {
	d[0][0] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		int x = pq.top().second / 1000;
		int y = pq.top().second % 1000;
		int c = -pq.top().first;
		pq.pop();

		if (d[x][y] < c) continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int l = arr[nx][ny];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			if (d[nx][ny] > c + l) {
				d[nx][ny] = c + l;
				pq.push(make_pair(-d[nx][ny], nx * 1000 + ny));
			}
		}
	}
}

int main(void)
{
	int T = 0;
	
	while (true) {
		cin >> N;
		if (N == 0) break;
		T++;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				d[i][j] = INF;
			}
		}
		dijkstra();
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << d[i][j] + arr[0][0] << ' ';
			}
			cout << '\n';
		}*/
		cout << "Problem " << T << ": " << d[N - 1][N - 1] + arr[0][0] << '\n';
	}

	return 0;
}