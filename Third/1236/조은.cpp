#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	int N, M;
	cin >> N >> M;
	char** input = new char*[N];
	for (int i = 0; i < N; i++) {
		input[i] = new char[M];
	}

	bool* row = new bool[N] {false};
	bool* col = new bool[M] {false};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input[i][j];
			if (input[i][j] == 'X') {
				row[i] = true;
				col[j] = true;
			}
		}
	}

	int ans_r = 0, ans_c = 0;
	for (int i = 0; i < N; i++) {
		if (!row[i]) { ++ans_r; }
	}
	for (int i = 0; i < M; i++) {
		if (!col[i]) { ++ans_c; }
	}

	cout << max(ans_r, ans_c);

	return 0;
}
