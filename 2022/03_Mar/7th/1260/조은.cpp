#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adj[1001]; // 인접리스트
bool visited[1001];

void dfs(int cur) {
	visited[cur] = true;
	cout << cur << ' ';

	for(auto next : adj[cur]) {
		if(visited[next]) continue;
		dfs(next);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true; //
	while(!q.empty()) {
		int cur = q.front();
		cout << cur << ' ';
		q.pop();

		for(auto next : adj[cur]) {
			if(visited[next]) continue;
			q.push(next);
			visited[next] = true; //
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M, V;
	cin >> N >> M >> V;
	for(int i=0; i<M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	} // 입력

	for(int i=1; i<=N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(V); cout << '\n';
	fill(visited, visited+1001, false);
	bfs(V);
	
	return 0;
}