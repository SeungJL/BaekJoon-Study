// BOJ #7562 : 실패
#include <iostream>
#include <queue>
#define MAX 301
using namespace std;

int T, l;
int di[8] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int dj[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };
int cnt[MAX][MAX];

void bfs(int si, int sj, int ei, int ej) {
	queue<pair<int,int>> q;
	q.push({si, sj});
	cnt[si][sj] = 0;

	while (!q.empty()) {
		int ci = q.front().first;
		int cj = q.front().second;
		q.pop();
		for (int dir=0; dir<8; dir++) {
			int ni = ci + di[dir];
			int nj = cj + dj[dir];
			if (ni<0 || nj<0 || ni>=l || nj>=l) continue;
			if (cnt[ni][nj] >= 0) continue;
			q.push({ni, nj});
			cnt[ni][nj] = cnt[ci][cj] + 1;

			if (make_pair(ni,nj) == make_pair(ei,ej)) {
				cout << cnt[ni][nj] << '\n';
				return;
			}
		}
	}
}

int main() {
	cin >> T;
	
	while (T--) {
		cin >> l;

		pair<int,int> start, end;
		cin >> start.first >> start.second >> end.first >> end.second;

		fill(&cnt[0][0], &cnt[MAX-1][MAX-1], -1);

		if ((start.first == end.first) && (start.second == end.second)) {
			cout << 0 << '\n';
			break;
		}
		bfs(start.first, start.second, end.first, end.second);
	}

	return 0;
}