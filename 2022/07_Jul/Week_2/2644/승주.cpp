#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N;
	int A, B;
	int m, x, y, a, b;
	int visit[101] = {};
	vector <vector <int> >  V;

	cin >> N;
	cin >> A >> B;
	cin >> m;
	V.resize(N + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	queue <int> q;
	q.push(A);
	int cnt = 0;
	visit[A] = 1;
	while (!q.empty()) {
		int h = q.size();
		cnt++;
		for (int j = 0; j < h; j++) {
			int front = q.front();
			q.pop();
			for (int i = 0; i < V[front].size(); i++) {
				if (V[front][i] == B) {
					cout << cnt;
					return 0;
				}
				if (visit[V[front][i]] == 0) {
					visit[V[front][i]] = 1;
					q.push(V[front][i]);
				}
			}
		}
	}
	cout << -1;
}