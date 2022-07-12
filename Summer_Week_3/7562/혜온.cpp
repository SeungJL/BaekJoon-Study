#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int T, sizeN;
int dx[8] = { 2, 2,1 ,1,-1 ,-1,-2,-2 };
int dy[8] = { 1,-1,2,-2, 2, -2 ,1,-1 };
//int dx[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
//int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };



pair<int, int>Start, End;
bool check[300][300];

void bfs(int x, int y)
{
	queue<pair<pair<int, int>, int>>q;
	q.push(make_pair(make_pair(x, y), 0));
	check[x][y] = true;

	while (!q.empty())
	{
		int a = q.front().first.first;
		int b = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (a == End.first && b == End.second)
		{
			cout << cnt << endl;
			return;
		}

		for (int i = 0; i < 8; i++)
		{
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (nx >= 0 && ny >= 0 && nx < sizeN && ny < sizeN)
			{
				if (!check[nx][ny])
				{
					check[nx][ny] = true;
					q.push(make_pair(make_pair(nx, ny), cnt + 1));


				}
			}
		}

	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	cin >> T;


	while (T--)
	{
		cin >> sizeN;
		cin >> Start.first >> Start.second;
		cin >> End.first >> End.second;

		bfs(Start.first, Start.second);
		memset(check, false, sizeof(check));
	}
}