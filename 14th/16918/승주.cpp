#include <iostream>

using namespace std;

int R, C, N;

void Bomb(int arr[][201]) {
	int visit[201][201] = {};
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visit[i][j] == 1) { continue; }
			if (arr[i][j] == '.') {
				arr[i][j] = 'O';
			}
			else if (arr[i][j] == 'O') {
				arr[i][j] = 1;
			}
			else if (arr[i][j] == 1) {
				arr[i][j] = 2;
			}
			else {
				arr[i][j] = '.';
				if (i + 1 < R) {
					if (arr[i + 1][j] == 2) {
					}
					else {
						arr[i + 1][j] = '.';
						visit[i + 1][j] = 1;
					}
				}
				if (j + 1 < C) {
					if (arr[i][j + 1] == 2) {

					}
					else {
						arr[i][j + 1] = '.';
						visit[i][j + 1] = 1;
					}
				}
				if (i - 1 >= 0) {
					arr[i - 1][j] = '.';
				}
				if (j - 1 >= 0) {
					arr[i][j - 1] = '.';
				}
			}
		}
	}
}

int main() {
	int arr[201][201];
	char c;

	cin >> R >> C >> N;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> c;
			if (c == '.') { arr[i][j] = c; }
			else { arr[i][j] = 1; }
		}
	}
	if (N == 1) {

	}
	else {
		;
		for (int i = 0; i < N - 1; i++) {
			Bomb(arr);
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == '.') { cout << '.'; }
			else { cout << 'O'; }
		}
		cout << endl;
	}
}