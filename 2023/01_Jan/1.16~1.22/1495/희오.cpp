// https://hio9105.tistory.com/entry/BOJ-1495-%EA%B8%B0%ED%83%80%EB%A6%AC%EC%8A%A4%ED%8A%B8-dp

#include <iostream>

using namespace std;

int N, S, M;
int v_list[50] = {};
bool dp[50][1001] = {};
int maxV = -1;

void dfs(int depth, int v) {
	if (depth == N) {
		if (v > maxV) maxV = v;
		return;
	}
	if (dp[depth][v]) return;
	dp[depth][v] = true;

	if (v + v_list[depth] <= M) 
		dfs(depth+1, v + v_list[depth]);
	if (v - v_list[depth] >= 0) 
		dfs(depth+1, v - v_list[depth]); 
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	cin >> N >> S >> M;
	for (int i=0; i<N; i++) cin >> v_list[i];

	dfs(0, S);
	cout << maxV << "\n";
}