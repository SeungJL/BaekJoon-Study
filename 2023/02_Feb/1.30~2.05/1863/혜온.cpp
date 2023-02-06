#include<iostream>
#include<vector>

using namespace std;

//vector<int> city[500002];
bool visit[500002];


//vector<int> city[500002];



int n, ans;
int main()
{


	cin >> n;
	vector<vector<int>> city(500002, vector<int>(n + 4));
	cout << city.size() << endl;
	int x, y;
	int size = 0, height = 0;
	int xx = 1, yy = 1;
	for (int i = 1; i <= n; i++)//1은 건물이 있음, 2는 방문함,  0은 건물이 없음.
	{


		cin >> x >> y;
		/*if (y < yy)
		{
			for (int ii = 1; ii <= yy; ii++)
				for (int jj = x-1; jj > xx; jj--)
					city[ii][jj] = 1;
		}*/

		for (int j = y; j > 0; j--)
			city[j][i] = 1;
		//cout << "???" << endl;
		/*if (y > yy)
		{
			for (int ii = 1; ii <= yy; ii++)
				for (int jj = xx; jj < x; jj++)
					city[ii][jj] = 1;
		}*/
		//xx = x; yy = y;
		if (y > height)
			height = y;
		if (i == n - 1)
			size = x;
	}
	size++;
	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << city[i][j];
		cout << endl;
	}*/
	bool chk = false;
	for (int i = height; i >= 1; i--)
	{
		chk = false;
		for (int j = 1; j <= n + 1; j++)
		{
			if (visit[j])
				continue;
			if (city[i][j] == 1)
			{
				visit[j] = true;
				chk = true;
			}
			if (city[i][j] == 0 && chk)
			{
				//cout << i << "            " << j << endl;
				ans++;
				chk = false;

			}
		}
		//if (chk)
		//	ans++;
	}
	cout << ans;


}