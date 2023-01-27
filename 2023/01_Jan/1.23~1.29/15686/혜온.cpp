#include<iostream>
#include<cmath>

using namespace std;

int city[52][52];// 0은 빈 칸, 1은 집, 2는 치킨집
int n, m;
int dtc[102][15];
int temp, ans = 2000000000, mCnt, hCnt;
int arr[15];
bool visit[15];
int minD = 100000;

void backtracking(int depth, int index)
{

	if (depth == m + 1)
	{

		temp = 0;
		for (int i = 1; i <= hCnt; i++)
		{
			minD = 1000000;
			for (int j = 1; j <= m; j++)
			{
				if (dtc[i][arr[j]] < minD)
				{
					minD = dtc[i][arr[j]];
					//cout << i << " :"<< arr[j] <<"  "<< minD << endl;
				}

			}
			temp += minD;

		}
		if (temp < ans)
			ans = temp;
		return;

	}
	for (int i = index; i <= mCnt; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			arr[depth] = i;
			backtracking(depth + 1, i + 1);//index+1로 했음 ㅠ
			visit[i] = false;
		}
	}
}

void calculationD(int y, int x, int idx)
{
	int temp = 0;
	int mIdx = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (city[i][j] == 2)
			{
				temp = abs(y - i) + abs(x - j);
				dtc[idx][mIdx] = temp;
				mIdx++;

			}
		}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> city[i][j];
			if (city[i][j] == 2)
				mCnt++;
			if (city[i][j] == 1)
				hCnt++;


		}
	int index = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (city[i][j] == 1)
			{
				calculationD(i, j, index);
				index++;
			}
		}


	//m개를 뽑았을때 도시의 치킨 거리 계산
	backtracking(1, 1);
	cout << ans;



}