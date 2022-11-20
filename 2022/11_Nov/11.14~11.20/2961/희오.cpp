#include <iostream>

using namespace std;

int N;
unsigned int sour[11] = {};
unsigned int bitter[11] = {};
unsigned long long min_diff = 10000000000;

/* dfs: dfs를 이용하여 사용할 재료 조합을 구하고, 쓴맛 신맛 차이를 계산
 *
 * parameters - depth: dfs의 깊이, 사용한 재료의 개수
 *            - mul, sum: 사용한 재료로 계산한 쓴맛, 신밋
 *            - visited: 사용한 재료 체크
 * return - none
 */
void dfs(int depth, long long mul, long long sum, int visited) {
	// 쓴맛 신맛 차이 & 답 구하기
	unsigned long long diff = abs(mul - sum);
	if (diff < min_diff) 
		min_diff = diff;

	// 재귀 종료 조건
	if (depth == N)
		return;

	// dfs, 재귀를 이용해 조합 구하기
	for (int i=0; i<N; i++) {
		if ((visited & (1 << i)) != 0) continue;
		dfs(depth + 1, mul * sour[i], sum + bitter[i], visited | (1 << i));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	/* input */
	cin >> N;
	for (int i=0; i<N; i++)
		cin >> sour[i] >> bitter[i];

	/* solve */
	for (int i=0; i<N; i++)
		dfs(1, sour[i], bitter[i], (1 << i));

	/* print answer */
	cout << min_diff << "\n";
}