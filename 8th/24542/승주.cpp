#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
	vector<vector<int>> V;

	int N, M;
	int u, v;

	cin >> N >> M;
	V.resize(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	vector <bool> visit(N + 1);
	queue <int> q;

	long long ans = 1;
	for (int i = 1; i < V.size(); i++) {

		if (V[i].empty() == 0 && visit[i] == 0) {
			int cnt = 0;
			q.push(i);
			cnt++;
			visit[i] = 1;
			while (q.empty() == 0) {
				int x = q.front();
				q.pop();
				for (int j = 0; j < V[x].size(); j++) {
					if (visit[V[x][j]] == 0) {
						q.push(V[x][j]);
						cnt++;
						visit[V[x][j]] = 1;
					}
				}
			}
			ans *= (long long)cnt;
			if (ans >= 1000000007) {
				ans %= 1000000007;
			}
		}

	}
	cout << ans;
}
