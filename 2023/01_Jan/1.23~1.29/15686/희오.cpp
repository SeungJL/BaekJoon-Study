// https://hio9105.tistory.com/entry/BOJ-15686-%EC%B9%98%ED%82%A8-%EB%B0%B0%EB%8B%AC-backtracking-bruteforcing-implementation

#include <iostream>
#include <vector>

using namespace std;

struct Point {
	int r, c;
};

int N, M;                 // N: 집의 개수, M: 치킨가게 최대 개수
vector<Point> chickens;   // 기존의 치킨가게 좌표 리스트
vector<Point> houses;     // 집의 좌표 리스트
int dist[100][15] = {};   // 집과 치킨 가게 사이의 거리, dist[i][j] = houses의 i번째 집과 chickens의 j번째 치킨가게 사이 거리
vector<int> comb;         // M개의 치킨가게 조합 
int answer = 100000000;   // 도시의 치킨 거리 최솟값 

/* get_total_dist: comb에 있는 M개의 치킨가게가 남았다고 했을 때의 도시의 치킨 거리를 구하는 함수 */
int get_total_dist() {
	int ret = 0;                       // 도시의 치킨 거리
	for (int h=0; h<houses.size(); h++) {
		int min_dist = 100000000;  // h번째 집의 치킨 거리
		for (auto c : comb)
			min_dist = min(min_dist, dist[h][c]);
		ret += min_dist;
	}
	return ret;
}

/* dfs: 가능한 모든 M개의 치킨가게 조합을 만들고, 그때의 도시의 치킨 거리를 구해, 도시의 치킨 거리의 최솟값을 구하는 함수 */
void dfs(int depth, int last) {
	if (depth == M) {
		answer = min(get_total_dist(), answer);
		return;
	}

	for (int i=last+1; i<chickens.size(); i++) {
		comb.push_back(i);
		dfs(depth+1, i);
		comb.pop_back();
	}
}

/* get_dist: 모든 (집, 치킨 가게) 사이의 거리를 구하는 함수 */
void get_dist() {
	for (int h=0; h<houses.size(); h++) {
		for (int c=0; c<chickens.size(); c++) {
			dist[h][c] = abs(houses[h].r - chickens[c].r) + abs(houses[h].c - chickens[c].c);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);
	
	/* input & init */
	cin >> N >> M;
	int input;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			cin >> input;
			if (input == 1) houses.push_back({i, j});
			else if (input == 2) chickens.push_back({i, j});
		}
	}

	/* solve */
	get_dist();
	dfs(0, -1);
	cout << answer << "\n";
	
}