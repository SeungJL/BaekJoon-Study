#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	int N, M;
	cin >> N >> M;
	int** arr = new int* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	// arr[i][j]가 정사각형 왼쪽 위 꼭짓점이라고 치고 브루트포스
	int l = 1;
	if (N == 1 || M == 1) {
		cout << 1;
		return 0;
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				for (int k = min(N - i - 1, M - j - 1); k > 0; k--) {
					if (k < l) break;
					if (arr[i][j] == arr[i][j + k]
						&& arr[i][j] == arr[i + k][j]
						&& arr[i][j] == arr[i + k][j + k]) {
						l = max(k + 1, l);
						break;
					}
				}
			}
		}
	}
	cout << l * l;

	return 0;
}
