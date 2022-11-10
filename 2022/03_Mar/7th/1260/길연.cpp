// 백준 1260번 DFS와 BFS
// 2022년 03월 06일

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, m, v;
int graph[1001][1001] = { 0 };
bool visited[1001] = { 0 };
queue<int> q;

void DFS(int v) {
	cout << v << " ";

	for (int i = 1; i <= n; i++) {
		if (graph[v][i] == 1 && visited[i] == 0) {  // 해당 노드 존재하고, 방문안했으면
			visited[i] = 1;
			DFS(i);
		}
	}
}

void BFS(int v) {
	q.push(v);

	while (!q.empty()) {
		v = q.front();
		cout << v << " ";
		q.pop(); // 원소 빼주고

		for (int i = 1; i <= n; i++) {
			if (graph[v][i] && visited[i] == 0) {
				visited[i] = 1;
				q.push(i); //인접노느 for문 돌면서 추가
			}
		}

	}
}

int main() {
	int start, end;
	cin >> n >> m >> v;
	
	while (m--) {
		cin >> start >> end;
		graph[start][end] = 1;
		graph[end][start] = 1;
	}

	visited[v] = 1;
	DFS(v);
	cout << endl;
	
	memset(visited, 0, sizeof(visited));

	visited[v] = 1;
	BFS(v);
	cout << endl;

	return 0;
}
