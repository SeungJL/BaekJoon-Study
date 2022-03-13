#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[200001];
bool visited[200001];

/* ��������Ʈ�� Ž���ϸ鼭 �� �������� ������ ���� �������� */
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
			int cnt = 0;
			ans *= dfs(i, cnt); // �� �������� ��ü ��� ���� ���� �����ش�
			ans %= 1000000007;
		}
	}
	cout << ans;

	return 0;
}