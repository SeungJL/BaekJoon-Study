#include <iostream>
#include <queue>

using namespace std;

int arr[1001][1001];

int main() {
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	int M, N; // 가로 길이, 세로 길이
	int number = 0;
	int cnt = 0;
	queue <pair<int, int>> Q;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				Q.push(make_pair(j, i));
				number++;
			}
			else if (arr[i][j] == -1) {
				number++;
			}
		}
	}
	while (!Q.empty()) {
		int Q_size = Q.size();
		cnt++;
		for (int i = 0; i < Q_size; i++) {
			int Q_x = Q.front().first;
			int Q_y = Q.front().second;
			Q.pop();
			for (int j = 0; j < 4; j++) {
				if (Q_x + dx[j] >= 0 && Q_x + dx[j] < M && Q_y + dy[j] >= 0 && Q_y + dy[j] < N && arr[Q_y + dy[j]][Q_x + dx[j]] == 0) {
					arr[Q_y + dy[j]][Q_x + dx[j]] = 1;
					number++;
					Q.push(make_pair(Q_x + dx[j], Q_y + dy[j]));
				}
			}
		}
	}
	if (M * N == number) {
		cout << cnt - 1;
	}
	else {
		cout << -1;
	}
}