#include <iostream>
#include <vector>

using namespace std;

#define INF 100000000
#define _to first 
#define _cost second 

int N, M;
vector<pair<int, int>> G[1001]; // 각 도시끼리의 버스 비용

/* get_min: 출발 도시에서부터 가장 가까운 도시를 찾는 함수
 *
 * parameters - SP: 출발도시에서부터 각 도시까지의 최소 경로
 *            - ch: 최소 경로를 찾기 위한 중간 경로로 사용했는지를 체크하는 배열
 * return - 아직 중간 경로로 사용하지 않은 도시 중 출발 도시에서부터 가장 용까운 도시 번호
 */
int get_min(vector<int> SP, vector<bool> ch) {
	int min_cost = INF, min_city = 0;
	for (int i=1; i<=N; i++) {
		if (ch[i]) continue;
		if (SP[i] < min_cost) {
			min_cost = SP[i];
			min_city = i;
		}
	}
	return min_city;
}

/* solve: 출발 도시에서 도착 도시까지의 최소 경로를 찾는 함수
 *        다익스트라 이용
 *
 * parameters - from: 출발 도시
 *            - to: 도착 도시
 * return - 출발 도시에서 도착 도시까지의 최소 경로 
 */
int solve (int from, int to) {
	vector<bool> ch(N+1, false);	// 중간 도시로 사용했는지 체크
    vector<int> SP(N+1, INF);		// 출발 도시에서 각 도시까지의 최소 경로
	for (auto e : G[from])
		SP[e._to] = e._cost;
	SP[from] = 0;

	while (1) {
		// 아직 중간도시로 사용하지 않은 도시 중 출발 도시에서 가장 가까운 도시 찾기 
		int cur = get_min(SP, ch);
		ch[cur] = true;

		// 종료 조건
		if (cur == to)
			return SP[to];

		// 위에서 찾은 중간 도시를 거쳐 갈 경우와 기존의 비용을 비교하여 SP 업데이트
		for (auto e : G[cur]) {
			SP[e._to] = min(SP[e._to], SP[cur] + e._cost);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int from, to, cost;

	/* input */
	cin >> N >> M;
	while (M--) {
		cin >> from >> to >> cost;
		G[from].push_back(make_pair(to, cost));
	}
	cin >> from >> to;

	/* solve */
	cout << solve(from, to) << "\n";

}