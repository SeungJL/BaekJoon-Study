#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, E, v1, v2, c, x, y, cnt1 = 0, cnt2 = 0;
int INF = 987654321;
int ans = INF;
vector<pair<int, int>> a[801];
int d[801];

void dijkstra(int start) {
	for (int i = 1; i <= N; i++) d[i] = INF;
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));
	while (!pq.empty()) {
		int cur = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();

		if (d[cur] < distance) continue;
		for (int i = 0; i < a[cur].size(); i++) {
			int next = a[cur][i].first;
			int nextDistance = distance + a[cur][i].second;
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main(void)
{
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		cin >> v1 >> v2 >> c;
		a[v1].push_back(make_pair(v2, c));
		a[v2].push_back(make_pair(v1, c));
	}

	dijkstra(1);
	cin >> x >> y;
	cnt1 += d[x];	//1�� �������� x�� ���������� �ִܰŸ�
	cnt2 += d[y];	//1�� �������� y�� ���������� �ִܰŸ�


	dijkstra(x);
	cnt1 += d[y];	//x�� �������� y�� ���������� �ִܰŸ�
	int tmp = d[y];
	cnt2 += d[N];	//x�� �������� N�� ���������� �ִܰŸ�

	dijkstra(y);
	cnt1 += d[N];	//y�� �������� N�� ���������� �ִܰŸ�
	cnt2 += d[x];	//y�� �������� x�� ���������� �ִܰŸ�

	ans = min(ans, cnt1);
	ans = min(ans, cnt2);
	if (tmp == INF || ans == INF) {	//x�� �������� y�� ���������� ��ΰ� ���ų� 1�� �������� N�� ���������� ��ΰ� ���� ���
		cout << -1;
	}
	else {
		cout << ans;
	}

	return 0;
}