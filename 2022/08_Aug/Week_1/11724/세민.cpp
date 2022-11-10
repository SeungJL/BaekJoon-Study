#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> graph[1001];
bool visited[1001];

void DFS(int node)
{
	visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];

		if (!visited[next])
			DFS(next);
	}
}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;

		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			DFS(i);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}