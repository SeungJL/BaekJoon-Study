#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1000000000

struct City {
	int cost, effect;

	bool operator< (const City &x) const {
		return cost < x.cost;
	}
} list[20];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	/* input */
	int C, N; // C: 늘려야 하는 최소 고객 수, N: 도시의 수
	cin >> C >> N;

	for (int i=0; i<N; i++) {
		cin >> list[i].cost >> list[i].effect;
	}
	sort(list, list + N);

	/* solve */
	int dp[100000] = {};	// i(total_cost)의 비용을 투자했을 때, 늘릴 수 있는 고객의 최댓값
	int res = INF;			// C 명의 고객을 늘리기 위해 필요한 최소 비용
	for (int i=0; i<N; i++) {
		int total_cost = 0;
		// i번째 도시까지 홍보에 이용한다고 했을 때, C명의 고객을 늘리기 위해 필요한 최소 비용 계산 
		while (dp[total_cost] < C) {
			total_cost++;
			if (list[i].cost <= total_cost) {
				dp[total_cost] = max(dp[total_cost], dp[total_cost - list[i].cost] + list[i].effect);
			}
		}
		if (total_cost < res) res = total_cost;
	}

	cout << res << "\n";
}