#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
void BFS();
void DFS(int x);
int visit[1001] = {};
queue <int> q;
vector <vector<int>> v;

int main() {
	int  M, K;
	cin >> N >> M >> K;

	v.resize(N + 1);

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < v.size(); i++) {
		sort(v[i].begin(), v[i].end());
	}
	visit[K] = 1;
	cout << K << " ";
	DFS(K);
	cout << endl;
	memset(visit, 0, sizeof(visit));
	visit[K] = 1;
	q.push(K);
	BFS();

}

void DFS(int x) {
	for (int i = 0; i < v[x].size(); i++) {
		if (visit[v[x][i]] == 0) {
			cout << v[x][i] << " ";
			visit[v[x][i]] = 1;
			DFS(v[x][i]);
		}
	}
}

void BFS() {
	int flag = 0;
	while (q.empty() == 0) {
		int x = q.front();
		cout << x << " ";
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			if (visit[v[x][i]] == 0) {
				visit[v[x][i]] = 1;
				q.push(v[x][i]);
				flag = 1;
			}
		}
		if (flag == 0) { return; }
	}
}