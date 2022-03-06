#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
bool isVisited[1001];

void dfs(int index) {
	isVisited[index] = true;
	cout << index << ' ';

	int i = 0;
	while (true) {
		if (i >= graph[index].size()) return;
		if (!isVisited[graph[index][i]]) dfs(graph[index][i]);
		i++;
	}
}

void bfs(int start) {
	fill(isVisited, isVisited + 1001, false);

	queue<int> q;
	q.push(start);
	isVisited[start] = true;
	int now;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		cout << now << ' ';
		int i = 0;
		while (true) {
			if (i >= graph[now].size()) break;
			if (!isVisited[graph[now][i]]) {
				q.push(graph[now][i]);
				isVisited[graph[now][i]] = true;
			}
			i++;
		}
	}
}

int main() {
	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}
	for (int i = 1; i <= N; i++) 
		sort(graph[i].begin(), graph[i].end());

	dfs(V);
	cout << endl;
	bfs(V);
	cout << endl;

	return 0;
}