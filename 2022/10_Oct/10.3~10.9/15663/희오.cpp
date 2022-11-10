// 15563

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
int input[10] = {};

/* dfs: N개의 숫자 중 M개의 숫자를 이용해 중복없는 순열을 만드는 함수
 *
 * parameter - depth: dfs의 depth, depth번 째에 숫자를 넣음 
 *           - visited: 이미 배열에 넣은 숫자를 체크하기 위한 변수, depth-1개의 사용된 숫자를 체크
 *           - perm: depth - 1까지의 순열
 */
void dfs(int depth, int visited, string perm) {
	if (depth == M) {
		cout << perm << "\n";
		return;
	}

	for (int i=0; i<N; i++) {
		if ((visited & (1 << i)) != 0) continue;
		if ((visited & (1 << (i+1))) == 0 && input[i] == input[i+1]) continue; // 중복 방지
		dfs(depth + 1, visited | (1 << i), perm + to_string(input[i]) + " ");
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	/* input */
	cin >> N >> M;
	for (int i=0; i<N; i++) cin >> input[i];

	/* solve */
	sort(input, input+N);
	dfs(0, 0, "");
}