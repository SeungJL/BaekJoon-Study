#include <bits/stdc++.h>
using namespace std;

bool visited[1000001];
vector<int> v[1001];

void dfs(int now)
{
	visited[now] = 1;
	for (int i = 0; i < v[now].size(); i++)
	{
		int next = v[now][i];
		if (!visited[next])
			dfs(next);
	}
}

int main()
{
	int n, m;
	int a, b;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int j = 1; j <= n; j++)
	{
		sort(v[j].begin(), v[j].end());
	}

	int cnt = 0;
	for (int k = 1; k <= n; k++)
	{
		if (visited[k])
			continue;
		dfs(k);
		cnt++;
	}

	cout << cnt;
	return 0;
}
