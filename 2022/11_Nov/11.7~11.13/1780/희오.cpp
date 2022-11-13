#include <iostream>

using namespace std;

int input[3000][3000] = {};
int res[3] = {}; // 타입별 종이의 개수, [0] = -1, [1] = 0, [2] = 1 

/* check: 종이가 모두 같은 수로 구성되어 있는지 확인하는 함수
 *
 * parameters - r, c, size: 확인하고자 하는 종이의 위치와 크기
 *            - (r, c)애 위기한 size * size 크기의 종이를 체크
 * return - 모두 같은 수로 되어있으면 true, 아니면 false
 */
bool check(int r, int c, int size) {
	int target = input[r][c];

	for (int i=r; i<r+size; i++) {
		for (int j=c; j<c+size; j++) {
			if (input[i][j] != target) 
				return false;
		}
	}
	return true;
}

/* solve: check()를 이용하여 종이가 모두 같은 숫자로 구성되어 있는지 확인하고,
 *        모두 같은 숫자일 경우, 해당 타입의 종이 개수에 체크
 *        아닐 경우, 종이를 9등분 하여 재귀를 통해 위 동작을 반복
 *
 * parameters - r, c, size: 확인하고자 하는 종이의 위치와 크기 
 *            - (r, c)애 위기한 size * size 크기의 종이를 체크
 * return - none
 */
void solve(int r, int c, int size) {
	// 종이 사이즈가 1일 경우
	if (size == 1) {
		res[input[r][c] + 1]++;
		return; 
	}

	// 종이가 모두 같은 숫자로 구성되어 있는 경우
	if (check(r, c, size)) {
		res[input[r][c] + 1]++;
		return;
	}

	// 종이가 모두 같은 숫자로 구성되어 있지 않은 경우, 9등분 
	int new_size = size / 3;
	for (int i=r; i<r+size; i+=new_size) {
		for (int j=c; j<c+size; j+=new_size) {
			solve(i, j, new_size);
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	/* input */
	int N;
	cin >> N;

	for (int r=1; r<=N; r++) {
		for (int c=1; c<=N; c++) {
			cin >> input[r][c];
		}
	}

	/* solve */
	solve(1, 1, N);

	/* print answer */
	for (int i=0; i<3; i++)
		cout << res[i] << "\n";

}