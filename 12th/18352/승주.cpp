#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <utility>


using namespace std;

vector <vector<int>> V;
vector <bool> visit;
vector <int> ans;
int K;

void BFS(int start, int cnt) {
	queue <pair<int, int>> q;
	q.push(make_pair(start, 0));

	while (!q.empty()) {
		int cur = q.front().first;
		int num = q.front().second;
		if (num == K && visit[cur] == 0) {
			ans.push_back(cur);
		}
		q.pop();
		visit[cur] = 1;
		for (int i = 0; i < V[cur].size(); i++) {
			if (num + 1 <= K && visit[V[cur][i]] == 0) {
				q.push(make_pair(V[cur][i], num + 1));
			}
		}
	}
}


int main() {
	int N, M, X;
	int a, b;

	cin >> N >> M >> K >> X;
	V.resize(N + 1);
	visit.resize(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		V[a].push_back(b);
	}

	BFS(X, 0);
	if (ans.size() == 0) {
		cout << -1;
		return 0;
	}
	else {
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << endl;
		}
	}
}