#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
char map[101][101] = {};	//�̷�
bool visit[101][101] = {false, };	//�湮 ����
int check[101][101] = {};	//���������κ����� �Ÿ�
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void BFS(int x, int y)	//�ʺ�켱Ž��
{
	visit[x][y] = true;	//�湮
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
				if (map[nx][ny] == '1' && !visit[nx][ny]) {	//�̵��� �� �ְ� �湮�� ���� ���� ���
					check[nx][ny] = check[x][y] + 1;
					visit[nx][ny] = true;	//�湮
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {	//�̷ΰ� �پ �Է����� �־���
		cin >> map[i];
	}

	BFS(0, 0);	//(0,0)���� ����Ͽ� (N-1, M-1)�� ��ġ�� �̵�

	cout << check[N - 1][M - 1] + 1;	//(N-1, M-1) ������ġ, ������ġ�� �����Ͽ� ĭ ����
	return 0;
}