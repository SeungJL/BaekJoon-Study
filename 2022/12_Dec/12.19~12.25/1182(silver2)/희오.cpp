#include <iostream>

using namespace std;

int N, S;
int arr[20] = {};
int ans = 0;

void dfs (int depth, int sum) {
	if (depth == N) return;
	if (sum + arr[depth] == S) ans++;

	dfs(depth + 1, sum + arr[depth]);   // depth 번째 원소를 부분수열에 포함하는 경우
	dfs(depth + 1, sum);                // depth 번째 원소를 부분수열에 포함하지 않는 경우
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);
    
	/* input */
	cin >> N >> S;
	for (int i=0; i<N; i++) cin >> arr[i];

	/* solve */
	dfs(0, 0);
    
	/* print answer */
	cout << ans << "\n";
}