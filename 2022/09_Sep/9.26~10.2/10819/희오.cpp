// 10819

#include <iostream>

using namespace std;

int N;              // input으로 들어올 배열 A의 크기
int input[10] = {}; // input으로 들어올 배열 A
int max_res = 0;    // 출력할 답, 배열에 들어 있는 수의 순서를 바꿔 얻을 수 있는 식의 최댓값

/* my_abs: 절댓값 반환 함수
 *
 * parameter - x: 절댓값으로 변환할 숫자 
 * return: |x|
 */
int my_abs(int x) {
	return (x >= 0) ? x : -x;
}

/* dfs: 배열 A에 있는 숫자의 순서를 바꾸기 위한 함수, 가능한 모든 경우(순서)를 구함
 * 
 * parameter - depth: dfs의 depth, depth번 째에 숫자를 넣음 
 *           - visited: 이미 배열에 넣은 숫자를 체크하기 위한 변수, depth-1개의 사용된 숫자를 체크
 *           - res: depth-1 개의 숫자를 식에 넣었을 때의 결과값
 *           - last: depth-1번 째 숫자, 식의 결과를 구하기 위해 필요
 */
void dfs(int depth, int visited, int res, int last) {
	if (depth == N) { // N개의 숫자를 모두 사용해 새로운 순서의 배열을 만들었을 때
		if (res > max_res) max_res = res;
		return;
	}

	for (int i=0; i<N; i++) {
		if ((visited & (1 << i)) == 0)
			dfs(depth + 1, visited | (1 << i), res + my_abs(last - input[i]), input[i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	/* input */
	cin >> N;
	for (int i=0; i<N; i++) cin >> input[i];

	/* solve */
	for (int i=0; i<N; i++) {
		dfs(1, 1 << i, 0, input[i]);
	}

	cout << max_res << "\n";
}