#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int check[20001];
vector<vector<int> > graph(20001);
vector<int> ans;
int cnt = 1;

void bfs() {
	queue<int> q;
	q.push(1);
	check[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto& next : graph[cur]) {
			if (check[next])continue;
			if (check[cur] + 1 == cnt) {
				check[next] = check[cur] + 1;
				q.push(next);
				ans.push_back(next);
			}
			else if (check[cur] + 1 > cnt) {
				ans.clear();
				check[next] = check[cur] + 1;
				q.push(next);
				cnt = check[next];
				ans.push_back(next);

			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	bfs();
	sort(ans.begin(), ans.end());
	cout << ans[0] << " " << check[ans[0]] - 1 << " " << ans.size();

	return 0;
}