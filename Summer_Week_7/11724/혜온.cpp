#include<iostream>
#include<vector>

using namespace std;
bool visited[10001];
vector<int> graph[10001];

void dfs(int node)
{
	visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++)
	{
		if (!visited[graph[node][i]])
		{
			dfs(graph[node][i]);
		}
	}
}
int main()
{
	int n, m;

	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);

	}
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			dfs(i);
			count++;
		}
	}
	cout << count;
}