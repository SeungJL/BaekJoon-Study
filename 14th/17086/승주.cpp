#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[100][100];
int visit[100][100] = {};
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

int main() {

	cin >> N >> M;
	queue<pair<int, int>> q;
	pair <int, int> p;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
				visit[i][j] = 1;
			}
		}
	}
	int value = 0;
	while (q.empty() == 0) {
		int q_size = q.size();
		value++;
		for (int i = 0; i < q_size; i++) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++) {
				if (a + dy[i] >= 0 && b + dx[i] >= 0 && a + dy[i] < N && b + dx[i] < M && visit[a + dy[i]][b + dx[i]] == 0) {
					visit[a + dy[i]][b + dx[i]] = 1;
					arr[a + dx[i]][b + dy[i]] = value;
					q.push(make_pair(a + dy[i], b + dx[i]));
				}
			}
		}
	}
	cout << value - 1;
}