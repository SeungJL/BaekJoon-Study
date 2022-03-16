#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[200001];
bool visited[200001];

/* 인접리스트를 탐색하면서 한 연결요소의 개수를 최종 리턴해줌 */
int dfs(int cur, int &cnt) {
	visited[cur] = true;
	cnt++;
	for(auto next : adj[cur]) {
		if(visited[next]) continue;
		dfs(next, cnt);
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);

	int N, M;
	cin >> N >> M;

	int u, v;
	while (M--) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	long long ans = 1;
	for(int i=1; i<=N; i++) {
		if(!visited[i]) {
			ans *= dfs(i, cnt); // 각 연결요소의 전체 노드 수를 각각 곱해준다
			ans %= 1000000007;
		}
	}
	cout << ans;

	return 0;
}
