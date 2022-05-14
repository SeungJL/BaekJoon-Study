#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

vector <vector<int>> V(5001);
map <pair<int, int>, int> M;
queue <int> Que;
int N, Q;
int p, q, r, k, v;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;
	for (int i = 0; i < N - 1; i++) {
		cin >> p >> q >> r;
		V[p].push_back(q);
		V[q].push_back(p);
		M[make_pair(p, q)] = r;
		M[make_pair(q, p)] = r;
	}
	int cnt;
	for (int i = 0; i < Q; i++) {
		int visit[5001] = {};
		cin >> k >> v;
		Que.push(v);
		cnt = 0;
		int FIRST = v;
		while (Que.empty() == 0) {
			int temp = Que.front();
			visit[temp] = 1;
			Que.pop();
			for (int i = 0; i < V[temp].size(); i++) {
				if (visit[V[temp][i]] == 1) {
					continue;
				}
				if (temp == FIRST) {
					continue;
				}
				else if (M.find(make_pair(FIRST, V[temp][i])) != M.end()) {
					M[make_pair(FIRST, V[temp][i])] = min({ M[make_pair(FIRST,V[temp][i])],M[make_pair(FIRST, temp)], M[make_pair(temp, V[temp][i])] });
				}
				else {
					M[make_pair(FIRST, V[temp][i])] = min(M[make_pair(FIRST, temp)], M[make_pair(temp, V[temp][i])]);
				}
				if (M[make_pair(FIRST, V[temp][i])] >= k) {
					Que.push(V[temp][i]);
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			if (i != v) {
				if (M[make_pair(v, i)] >= k) {
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}
