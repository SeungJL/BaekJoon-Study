#include<iostream>
#include<cstring>

using namespace std;

int graph[8][8];
int n, m;
int sum = 0, ans = 0;
bool visit[8][8];
int tx, ty;
bool check[8][8];

//벽을 3개 세운 뒤 안전영역의 최대 크기
//0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치
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
			if (!check[ty][tx] && !graph[ty][tx] && !visit[ty][tx])//벽이 아니고 빈 칸이고 방문하지 않은 칸이면
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
		
		//바이러스가 퍼짐
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (graph[i][j] == 2)// && !visit[i][j])
				{

					dfs(i, j);

				}
			}
		
			//안전 영역의 크기를 구함
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				
				if (!check[i][j] && !graph[i][j] && !visit[i][j])//빈 칸이면서 바이러스가퍼지지 않은 칸
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
	//벽을 어디다 세울지 구함
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (!graph[i][j] && !check[i][j])//빈칸이고 방문하지 않았다면
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