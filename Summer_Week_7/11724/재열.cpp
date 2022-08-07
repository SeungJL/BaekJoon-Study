#include <iostream>
#include <vector>

using namespace std;

int is_visited[1001];
vector<int> graph[1001];
int c_count = 0;

void dfs(int now) {
	is_visited[now] = true;
	for (int i = 0; i < graph[now].size(); i++) {
		if (!is_visited[graph[now][i]])
			dfs(graph[now][i]);
	}
}

int main() {
	int N, M, e1, e2;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> e1 >> e2;
		graph[e1].push_back(e2);
		graph[e2].push_back(e1);
	}
	for (int i = 1; i <= N; i++) {
		if (!is_visited[i]) {
			dfs(i);
			c_count++;
		} 
	}
	cout << c_count << endl;

	return 0;
}
