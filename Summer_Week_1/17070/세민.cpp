#include <iostream>

using namespace std;

int N;
int m[17][17];

void dfs(int x, int y, int d)	// d(1~3; ���� ����, ����, �밢�� ����)
{
	m[x][y]++;
	if (d == 1 || d == 3) {	
		if (y < N && m[x][y + 1] != -1) {
			dfs(x, y + 1, 1);	//���η� �̵�
		}
	}
	if (d == 2 || d == 3) {
		if (x < N && m[x + 1][y] != -1) {
			dfs(x + 1, y, 2);	//���η� �̵�
		}
	}
	if (x < N && y < N && m[x][y + 1] != -1 && m[x + 1][y] != -1 && m[x + 1][y + 1] != -1)
		dfs(x + 1, y + 1, 3);	//�밢������ �̵�

}


int main(void)
{
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> m[i][j];
			if (m[i][j] == 1) m[i][j] = -1;	// ��: -1
		}
	}
	
	dfs(1, 2, 1);	//�������� ������ �� �ʱ� ��ġ�� (1,2)

	if (m[N][N] == -1) m[N][N] = 0;
	
	cout << m[N][N];

	return 0;
}