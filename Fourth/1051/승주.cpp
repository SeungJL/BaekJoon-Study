#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>

using namespace std;

int main() {
	int N, M;
	int arr[51][51] = {};
	bool visit[51][51] = {};

	cin >> N >> M;
	int x;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &x);
			arr[i][j] = x;
		}
	}
	int Max = 1;
	int h = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0) {
				int n = Max; // 어차피 최대값이니까 1부터 다 탐색할 필요 없다.
				while (1) {
					if (j + n >= M || i + n >= N) {
						break;
					}
					if (arr[i][j] == arr[i + n][j] && arr[i + n][j] == arr[i][j + n] && arr[i][j + n] == arr[i + n][j + n]) {
						h = 1;
						if (n > Max) {
							Max = n;
						}
					}
					n++;
				}
			}
		}
	}
	if (h == 0) {
		cout << 1;
		return 0;
	}
	cout << (Max + 1) * (Max + 1);
	return 0;
}
