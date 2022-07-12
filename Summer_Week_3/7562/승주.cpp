#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main() {
	int dx[8] = { 2,2,1,1,-1,-1,-2,-2 };
	int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };
	int T;
	int I, a, b, c, d;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> I >> a >> b >> c >> d;
		if (a == c && b == d) { cout << 0 << endl; break; }
		int visit[310][310] = {};
		int cnt = 0;
		queue <pair<int, int>> Q;
		Q.push(make_pair(a, b));

		while (!Q.empty()) {
			if (visit[c][d] == 1) {
				cout << cnt << endl;
				break;
			}
			int p = Q.size();
			cnt++;
			for (int j = 0; j < p; j++) {
				int front_x = Q.front().first;
				int front_y = Q.front().second;
				Q.pop();
				for (int k = 0; k < 8; k++) {
					if (visit[front_x + dx[k]][front_y + dy[k]] == 0) {
						visit[front_x + dx[k]][front_y + dy[k]] = 1;
						Q.push(make_pair(front_x + dx[k], front_y + dy[k]));
					}
				}
			}
		}
		memset(visit, 0, sizeof(visit));
	}
}