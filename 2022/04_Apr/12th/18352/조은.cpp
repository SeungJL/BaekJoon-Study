#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[300001];
vector<int> dist(300001);

void bfs(int start, int distance) {
	fill(dist.begin(), dist.end(), -1);
	queue<int> q;
	q.push(start);
	dist[start] = 0;

	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for(auto next : graph[cur]) {
			if(dist[next] != -1) continue;
			q.push(next);
			dist[next] = dist[cur]+1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	int u, v;
	while (M--) {
		cin >> u >> v;
		graph[u].push_back(v);
	}

	for(int i=1; i<=N; i++) 
		sort(graph[i].begin(), graph[i].end());

	bfs(X, K);

	bool flag = false;
	for(int i=1; i<=N; i++) {
		if(dist[i] == K) {
			flag = true;
			cout << i << '\n';
		}
	}
	if(!flag) cout << -1;
	
	return 0;
}