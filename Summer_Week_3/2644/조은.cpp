#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[500];
int cnt[500];

int bfs(int start, int end) {
	fill(cnt, cnt+500, -1);
	queue<int> q;
	q.push(start);
	cnt[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto next : adj[cur]) {
			if (cnt[next] >= 0) continue;
			q.push(next);
			cnt[next] = cnt[cur] + 1;

			if (next == end) return cnt[next];
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, A, B;
	cin >> n >> A >> B;
	int m;
	cin >> m;
	for(int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	cout << bfs(A, B);

	return 0;
}