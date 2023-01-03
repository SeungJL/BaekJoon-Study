#include <iostream>
#include <queue>

using namespace std;

/* solve: (r,c) 부터 N * N 크기 행렬에 대해 222-폴링을 적용시키는 함수
 * 		  4구역으로 나누어 각각의 구역에 222-폴링을 적용시켜 얻어낸 4개의 숫자 중 두 번째로 큰 수
 * 
 * parameters - matrix: input으로 주어진 행렬
 *            - N: 222-폴링을 적용시킬 행렬의 범위/크기
 *            - r,c: 222-폴링을 적용시킬 행렬의 시작 좌표
 * return - (r,c) 부터 N * N 크기 행렬에 222-폴링을 적용시킨 결과
 */
int solve(int **matrix, int N, int r, int c) {
	if (N == 1) 
		return matrix[r][c];

	priority_queue<int> PQ;

	PQ.push(solve(matrix, N/2, r, c));
	PQ.push(solve(matrix, N/2, r + N/2, c));
	PQ.push(solve(matrix, N/2, r, c + N/2));
	PQ.push(solve(matrix, N/2, r + N/2, c + N/2));

	PQ.pop();
	return (PQ.top());
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	/* input & init */
	int N;
	cin >> N;

	int **matrix = new int*[N];
	for (int i=0; i<N; i++) {
		matrix[i] = new int[N]{};
		for (int j=0; j<N; j++)
			cin >> matrix[i][j];
	}

	/* solve */
	cout << solve(matrix, N, 0, 0) << "\n";

	/* free memory */
	for (int i=0; i<N; i++)
		delete[] matrix[i];
	delete[] matrix;

	return 0;
}