#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int M, N;
int arr[1000][1000];	//�丶���� ������ �����ϴ� �迭
bool visit[1000][1000] = { false, };	//�湮 ���θ� �����ϴ� �迭
int path[1000][1000];	//�湮 ���ڸ� �����ϴ� �迭
queue<pair<int, int>> q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs()	//�ʺ� �켱 Ž��
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
	cin >> N >> M;	//����, ����
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	/*���� �丶�並 ã�� �ʺ� �켱 Ž���� ��������� ť�� push*/
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
			if (arr[i][j] == 0 && path[i][j] == 0) {	//�丶�䰡 ���� ���ϴ� ���(���� ���ϴ� �丶�䰡 ���������� �湮 �� ���� ����)
				cout << -1;
				return 0;
			}
		}
	}

	/*�湮 ���� �迭 �� �ִ� ���*/
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			ans = max(ans, path[i][j]);
		}
	}

	cout << ans;
}