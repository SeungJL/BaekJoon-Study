#include<iostream>

#include<cstring>

using namespace std;

int n, m;
int a, b, count1, count2;
int people[101][101];
bool check[101];
bool findB = 0;

void dfs(int a, int b, int count)
{
	check[a] = true;
	for (int i = 0; i <= n; i++)
	{
		if (!check[i] && i == b && people[a][i] == 1)
		{
			count1++;
			count2 = count1;
			memset(check, 1, 101);
			findB = 1;

		}
		if (!check[i] && people[a][i] == 1)
		{
			//	cout << a << "  " << i << endl;
			dfs(i, b, count1++);
			count1 -= 1;
		}


	}

}

int main()
{
	cin >> n;// 사람수
	cin >> a >> b;
	cin >> m; //관계 수
	int temp, temp2;
	for (int i = 0; i < m; i++)
	{
		cin >> temp >> temp2;
		people[temp][temp2] = 1;
		people[temp2][temp] = 1;

	}
	//cout << "====" << endl;
	dfs(a, b, 0);
	if (findB)
		cout << count2;
	else
		cout << -1;
	//dfs(b,a,0);
}