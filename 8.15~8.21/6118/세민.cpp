#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
bool visited[50001];
vector<int> graph[50001];

int dist[50001];

int bfs(int start) {
	int res = 0;
	visited[start] = true;
	queue<pair<int, int> >q;
	q.push(make_pair(start, 0));

	while (!q.empty()) {
		int v = q.front().first;
		int dis = q.front().second;
		if (dis > res)res = dis;
		dist[v] = dis;
		q.pop();

		for (int i = 0; i < graph[v].size(); i++) {
			if (!visited[graph[v][i]]) {
				visited[graph[v][i]] = true;
				q.push(make_pair(graph[v][i], dis + 1));
			}
		}
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	int ta, tb;
	for (int i = 1; i <= M; i++) {
		cin >> ta >> tb;
		graph[ta].push_back(tb);
		graph[tb].push_back(ta);
	}

	int res = 0;
	res = bfs(1);
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		if (dist[i] == res) {
			if (cnt == 0) cout << i << " ";
			cnt++;
		}
	}
	cout << res << " " << cnt << endl;
	return 0;
}