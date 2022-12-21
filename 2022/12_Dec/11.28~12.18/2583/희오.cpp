// 2583
// https://hio9105.tistory.com/entry/BOJ-2583-%EC%98%81%EC%97%AD-%EA%B5%AC%ED%95%98%EA%B8%B0-bfs-dfs-graphs-graphtraversal

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
	int m, n;
	Point(int _m, int _n) : m(_m), n(_n) {}
};

int M, N, K;

/* get_area: 직사각형에 포함되지 않는 나머지 영역의 넓이를 구하는 함수
 *           BFS를 이용해 이동할 수 있는(직사각형에 포함되지 않은) 모든 지점을 가보고 그 개수를 구함, 지점의 개수 = 넓이
 *
 * parameters - ch: 직사각형에 포함되어 있는지 여부
                (m, n): 영역이 시작되는 point
 * return - (m, n)에서 시작하여 직사각형에 포함되지 않은 영역의 넓이
 */
int get_area(vector<vector<bool>> &ch, int m, int n) {
	int ans = 0;

	queue<Point> Q;
	Q.push(Point(m, n));
	ch[m][n] = true;

	int MM[4] = {-1, 0, 1, 0};
	int NN[4] = {0, 1, 0, -1};
	while (!Q.empty()) {
		Point cur = Q.front(); Q.pop();
		ans++;

		for (int i=0; i<4; i++) {
			int next_m = cur.m + MM[i], next_n = cur.n + NN[i]; 
			if (next_m < 0 || next_m >= M || next_n < 0 || next_n >= N) continue;
			if (ch[next_m][next_n]) continue;
			Q.push(Point(next_m, next_n));
			ch[next_m][next_n] = true;
		}
	}
	return ans;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	/* input */
	cin >> M >> N >> K;

	vector<vector<bool>> paper(M, vector<bool>(N, false));
	while (K--){
		int n1, m1, n2, m2;
		cin >> n1 >> m1 >> n2 >> m2;
		for (int i = m1; i < m2; i++) {
			for (int j = n1; j < n2; j++)
				paper[i][j] = true;
		}
	}

	/* solve */
	vector<int> ans; // 직사각형에 포함되지 않는 나머지 영역의 넓이, ans의 원소 개수 = 나머지 영역의 개수
	for (int i=0; i<M; i++) {
		for (int j=0; j<N; j++) {
			if (!paper[i][j]) 
				ans.push_back(get_area(paper, i, j));
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto e : ans)
		cout << e << " ";
	
}