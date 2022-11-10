#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[200001];
bool visited[200001];
unsigned long long cnt;

void dfs(int n) {
	cnt++;
	cnt %= 1000000007;
	visited[n] = true;

	for (auto v : graph[n]) {
		if (!visited[v]) 
			dfs(v);
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	fill(visited, visited + 200001, false);

	unsigned long long result = 1;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			cnt = 0;
			dfs(i);
			result = ((result % 1000000007) * cnt) % 1000000007;
		}
	}

	cout << result << endl;
	return 0;
}