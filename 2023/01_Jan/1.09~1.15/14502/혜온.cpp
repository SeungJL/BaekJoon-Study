#include<iostream>
#include<cstring>

using namespace std;

int graph[8][8];
int n, m;
int sum = 0, ans = 0;
bool visit[8][8];
int tx, ty;
bool check[8][8];

//���� 3�� ���� �� ���������� �ִ� ũ��
//0�� �� ĭ, 1�� ��, 2�� ���̷����� �ִ� ��ġ
void dfs(int y, int x)
{

	visit[y][x] = true;
	int dy[4] = { 0,-1,0,1 };
	int dx[4] = { 1,0,-1,0 };

	for (int i = 0; i < 4; i++)
	{
		ty = y + dy[i];
		tx = x + dx[i];
		if (ty >= 0 && ty < n && tx >= 0 && tx < m)
		{
			if (!check[ty][tx] && !graph[ty][tx] && !visit[ty][tx])//���� �ƴϰ� �� ĭ�̰� �湮���� ���� ĭ�̸�
			{
				dfs(ty, tx);
			}
		}
	}

}
void backtracking(int y, int x, int depth)
{
	
	if (depth == 3)
	{
		
		//���̷����� ����
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (graph[i][j] == 2)// && !visit[i][j])
				{

					dfs(i, j);

				}
			}
		
			//���� ������ ũ�⸦ ����
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				
				if (!check[i][j] && !graph[i][j] && !visit[i][j])//�� ĭ�̸鼭 ���̷����������� ���� ĭ
				{

					sum++;
				}
			}
		if (sum > ans)
		{
			ans = sum;
			
		}

		sum = 0;
		memset(visit, 0, sizeof(visit));


		return;

	}
	//���� ���� ������ ����
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (!graph[i][j] && !check[i][j])//��ĭ�̰� �湮���� �ʾҴٸ�
			{

				check[i][j] = true;
				backtracking(i, j, depth + 1);
				check[i][j] = false;

			}
		}


}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> graph[i][j];
	
	backtracking(0, 0, 0);
	cout << ans;

}