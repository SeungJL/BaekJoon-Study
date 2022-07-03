#include<iostream>
#include<queue>

using namespace std;
int m, n, cnt, zero;//가로, 세로
int tomato[1001][1001];

queue<pair<int, int>>q;


void ripen(int y, int x)
{
	//cout << "y " << y << "  x " << x << endl;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	for (int i = 0; i < 4; i++)
	{
		if (y + dy[i] >= 0 && y + dy[i] < n && x + dx[i] >= 0 && x + dx[i] < m)
			if (tomato[y + dy[i]][x + dx[i]] != -1 && tomato[y + dy[i]][x + dx[i]] != 1)
			{
				q.push(make_pair(y + dy[i], x + dx[i]));
				tomato[y + dy[i]][x + dx[i]] = 1;
				zero--;
			}
	}


}
bool check(int y, int x)
{

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	for (int i = 0; i < 4; i++)
	{
		if (y + dy[i] >= 0 && y + dy[i] < n && x + dx[i] >= 0 && x + dx[i] < m)
		{
			if (tomato[y + dy[i]][x + dx[i]] != -1)
			{
				return true;
			}

		}
	}


	return false;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> tomato[i][j];
			if (tomato[i][j] == 1)
			{
				q.push(make_pair(i, j));
			}
			if (tomato[i][j] == 0)
				zero++;
		}
	


	while (zero > 0) {

		int temp = q.size();
		for (int i = 0; i < temp; i++)
		{

			ripen(q.front().first, q.front().second);

			q.pop();



		}
		cnt++;
		if (cnt > n * m + 1)
		{
			cout << "-1" << "\n";
			return 0;
		}

	}
	cout << cnt;
}