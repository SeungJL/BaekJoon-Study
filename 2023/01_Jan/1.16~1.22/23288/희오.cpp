#include <iostream>
#include <queue>

using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

#define LEFT_ROTATE 1
#define RIGHT_ROTATE 3

struct Dice {
	int left, right, up, down, top, bottom;       // 주사위 각 면의 숫자
	int *hor[4] = {&left, &top, &right, &bottom}; // 주사위 전개도 기준 가로 
	int *ver[4] = {&up, &top, &down, &bottom};    // 주사위 전개도 기준 세로

	// 움직이는 방향과 일치할 경우(hor) 이동 전 주사위의 hor에서 한 칸씩 밀림
	// 움직이는 방향의 수직인 경우(ver) hor과 겹치는 주사위 윗면과 아랫면만 바뀜, 나머지는 이동 전과 동일
	void move(int *dir_hor[], int *before_hor[], int *dir_ver[], int *before_ver[], int dir) {
		// 한 칸씩 밀리는 방향 - ( WEST, NORTH - 왼쪽으로 / EAST, SOUTH - 오른쪽으로 )
		int d = (dir == WEST || dir == NORTH) ? LEFT_ROTATE : RIGHT_ROTATE; 

		for (int i=0; i<4; i++)
			*dir_hor[i] = *before_hor[(i + d) % 4];
		*dir_ver[0] = *before_ver[0];
		*dir_ver[2] = *before_ver[2];
	}	

	void go2west(Dice before) {
		move(this->hor, before.hor, this->ver, before.ver, WEST);
	}
	void go2east(Dice before) {
		move(this->hor, before.hor, this->ver, before.ver, EAST);
	}
	void go2north(Dice before) {
		move(this->ver, before.ver, this->hor, before.hor, NORTH);	
	}
	void go2south(Dice before) {
		move(this->ver, before.ver, this->hor, before.hor, SOUTH);	
	}

	void operator=(const Dice &x) {
		this->left = x.left;
		this->right = x.right;
		this->top = x.top;
		this->bottom = x.bottom;
		this->up = x.up;
		this->down = x.down;
	}
};

struct Point {
	int x, y;
};

int N, M, K;
int map[22][22] = {};
int mv_cnt[22][22] = {};
Point DD[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void init() {
	// input
	cin >> N >> M >> K;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=M; j++)
			cin >> map[i][j];
	}

	// 지도의 각 칸에서 이동 가능한 칸의 개수 구하기
	// 이동 가능한 칸 = 지도에 쓰여져 있는 숫자가 같고, 현재 칸에서 동서남북 방향으로 연속해서 이동할 수 있는 칸
	queue<Point> Q, set;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=M; j++) {
			if (mv_cnt[i][j] > 0) continue; 
			
			// 이동 가능한 칸 구하지 않았으면 아래 실행
			// BFS로 현재 칸에서 상하좌우로 이동할 수 있고, 지도에 쓰인 숫자가 같은 칸을 구하고
			// 그 칸의 좌표를 set에 저장
			Q.push({i, j});
			mv_cnt[i][j] = 1;
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				set.push(cur);
				for (auto d : DD) {
					Point next = {cur.x + d.x, cur.y + d.y};
					if (!(0 < next.x && next.x <= N) || !(0 < next.y && next.y <= M) 
						|| mv_cnt[next.x][next.y] 
						|| map[next.x][next.y] != map[i][j]) continue;
					Q.push(next);
					mv_cnt[next.x][next.y] = 1;
				}
			}
			// set에 저장된 좌표의 개수 = (i, j)를 포함한 set에 저장된 칸에서 이동 가능한 칸의 개수
			int cnt = set.size();
			while (!set.empty()) {
				mv_cnt[set.front().x][set.front().y] = cnt; set.pop();
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);
	
	// input을 받고, 지도의 각 칸의 이동 가능한 칸의 개수를 구하기 
	init(); 

	int score = 0;
	int cur_d = EAST;
	Point cur = {1, 1}, next;
	Dice before = {4, 3, 2, 5, 1, 6}, after;

	while (K--) {
		// 주사위가 이동 방향으로 한 칸 굴러간다. 만약, 이동 방향에 칸이 없다면, 이동 방향을 반대로 한 다음 한 칸 굴러간다.
		// 주사위 위치한 칸과 주사위 전개도 변함
		next = {cur.x + DD[cur_d].x, cur.y + DD[cur_d].y};
		if (!(0 < next.x && next.x <= N) || !(0 < next.y && next.y <= M)) {
			cur_d = (cur_d + 2) % 4;
			next = {cur.x + DD[cur_d].x, cur.y + DD[cur_d].y};
		}
		switch(cur_d) {
			case NORTH : after.go2north(before); break;
			case EAST : after.go2east(before); break;
			case SOUTH : after.go2south(before); break;
			case WEST : after.go2west(before); break;
		}
		cur = next;
		before = after;

		// 주사위가 도착한 칸 (x, y)에 대한 점수를 획득한다.
		score += (map[cur.x][cur.y] * mv_cnt[cur.x][cur.y]);

		// 주사위의 아랫면에 있는 정수 A와 주사위가 있는 칸 (x, y)에 있는 정수 B를 비교해 이동 방향을 결정한다.
		if (after.bottom > map[cur.x][cur.y]) cur_d = (cur_d + LEFT_ROTATE) % 4;      // A > B인 경우 이동 방향을 90도 시계 방향으로 회전시킨다.
		else if (after.bottom < map[cur.x][cur.y]) cur_d = (cur_d + RIGHT_ROTATE) % 4; // A < B인 경우 이동 방향을 90도 반시계 방향으로 회전시킨다.
	}

	cout << score << "\n";	
}