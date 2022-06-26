#include <iostream>
#include <string>
#include <queue>
#include <stdio.h>
#include <utility>

using namespace std;

int main() {
	int N, M;
	int visit[102][102] = {};
	int arr[102][102] = {};
	int cnt = 0;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	cin >> N >> M;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	queue <pair<int, int>> q;
	q.push(make_pair(1, 1));

	while (1) {
		cnt++;
		int turn = q.size();
		while (turn--) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();
			visit[a][b] = 1;
			if (a == N && b == M) {
				cout << cnt;
				return 0;
			}
			for (int i = 0; i < 4; i++) {
				if (arr[a + dx[i]][b + dy[i]] == 0 || visit[a + dx[i]][b + dy[i]] == 1) {
					continue;
				}
				else {
					q.push(make_pair(a + dx[i], b + dy[i]));
					visit[a + dx[i]][b + dy[i]] = 1;
				}
			}
		}
	}
}

