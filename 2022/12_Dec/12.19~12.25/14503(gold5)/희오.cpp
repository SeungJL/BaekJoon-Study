#include <iostream>

using namespace std;

struct Point {
	int r, c;
	Point(int _r, int _c) : r(_r), c(_c) {}
};

#define NOTHING 0
#define WALL 1
#define CLEANED 2

int N, M;
int map[50][50] = {};

int RR[4] = {-1, 0, 1, 0};
int CC[4] = {0, 1, 0, -1};
int ans = 0;

/* solve: 재귀를 이용해 로봇청소기가 청소한 칸 수를 구하는 함수
 *
 * parameters - cur: 로봇청소기의 현재 위치/좌표 
 *              d: 로봇청소기가 바라보고 있는 현재 방향
 * return: none 
 */
void solve(Point cur, int d) {
	if (!map[cur.r][cur.c]) ans++;
	map[cur.r][cur.c] = CLEANED;

	int next_r, next_c, next_d;
	// 현재 위치의 왼쪽 방향부터 시작해서 반시계방향으로 돌면서 청소 가능한 곳 찾기
	for (int i=3; i>=0; i--) {
		next_d = (i + d) % 4;
		next_r = cur.r + RR[next_d];
		next_c = cur.c + CC[next_d];
		if (map[next_r][next_c] != NOTHING) continue;
		solve(Point(next_r, next_c), next_d);
		return;
	}
	// 현재 위치의 주변에 청소 가능한 곳이 없을 경우 
	// 청소 가능한 곳이 나올 때까지 후진 (처음 방향 기준) 
	next_r = cur.r;
	next_c = cur.c;
	while (true) {
		next_r -= RR[d];
		next_c -= CC[d];
		// 벽이 나오면 더 이상 청소 가능한 곳이 없음을 의미
		if (map[next_r][next_c] == WALL) return;
		solve(Point(next_r, next_c), d);
		return;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	int r, c, d;

	/* input */
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> map[i][j];
		}
	}

	/* solve */
	solve(Point(r, c), d);

	/* print answer */
	cout << ans << "\n";
}