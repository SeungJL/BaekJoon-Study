// https://hio9105.tistory.com/entry/BOJ-14502-%EC%97%B0%EA%B5%AC%EC%86%8C-bfs-bruteforcing-graphs-graphtraversal-implementation

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define WALL 1
#define VIRUS 2
#define ZERO 0

struct Point {
	int x, y;
	Point(int _x, int _y) : x(_x), y(_y) {}
};

int N, M;
int map[10][10] = {};
vector<Point> virus_loc;  // 바이러스 좌표 리스트 
vector<Point> zeroPoints; // 빈 칸 좌표 리스트 
int answer = 0;

/* check_safeArea: 안전구역의 넓이를 체크하는 함수
 *
 * no parameter
 * return - 안전구역의 넓이 
 */
int check_safeArea() {
	queue<Point> Q;
	vector<vector<bool>> ch(N+1, vector<bool>(M+1, false));

	for (auto v : virus_loc) {
		Q.push(v); ch[v.x][v.y] = true;
	}

	int XX[4] = {-1, 0, 1, 0};
	int YY[4] = {0, 1, 0, -1};
	int zero_cnt = zeroPoints.size() - 3; // 빈 칸 개수
	// 바이러스가 인접한 상하좌우로 퍼져나감
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		if (map[cur.x][cur.y] == ZERO) zero_cnt--; // 바이러스가 퍼진 빈 칸 제외 

		for (int d=0; d<4; d++) {
			auto next = Point(cur.x + XX[d], cur.y + YY[d]);
			if (next.x == 0 || next.x > N || next.y == 0 || next.y > M) continue;
			if (map[next.x][next.y] == WALL || map[next.x][next.y] == VIRUS) continue;
			if (ch[next.x][next.y]) continue;
			Q.push(next);
			ch[next.x][next.y] = true;
		}
	}

	return zero_cnt; // 초기의 빈 칸 중 바이러스가 퍼지지 않은 칸의 개수 
}

/* solve: 새로 세울 3개의 벽을 고르고, 그때의 안전구역의 넓이를 체크하여, 안전구역의 최댓값을 구하는 함수
 * 
 * parameters - depth: 현재까지 새로 세운 벽의 개수
 *            - cur: 벽을 새로 세울 수 있는 칸 
 * no return
 */
void solve(int depth, vector<Point>::iterator cur) {
	if (depth == 3) {
		int area_size = check_safeArea();
		answer = max(area_size, answer);
		return;
	}
	if (cur == zeroPoints.end()) return;

	// 현재 칸에 벽을 새로 세운 경우 
	map[cur->x][cur->y] = WALL;
	solve(depth+1, cur+1);
	// 벽을 세우지 않은 경우 
	map[cur->x][cur->y] = ZERO;
	solve(depth, cur+1);	
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	/* input & init */
	cin >> N >> M;
	for (int i=0; i<=N+1; i++) {
		for (int j=0; j<=M+1; j++) {
			if (i == 0 || i > N || j == 0 || j > M) {
				map[i][j] = WALL; continue;
			}
			cin >> map[i][j];
			if (map[i][j] == VIRUS) 
				virus_loc.push_back(Point(i, j));
			else if (map[i][j] == ZERO)
				zeroPoints.push_back(Point(i, j));
		}
	}

	/* solve & print answer */
	solve(0, zeroPoints.begin());
	cout << answer << endl;

}