#include <iostream>

using namespace std;

int arr[17][17];
int N;
int cnt = 0;

void DFS(int, int, int, int);

void Width_go(int a, int b, int c, int d) {
	if (arr[a][b + 2] == 0) {
		DFS(c, d, a, b + 2);
		if (arr[a + 1][b + 1] == 0) DFS(c, d, a + 1, b + 2);
	}
}

void Height_go(int a, int b, int c, int d) {
	if (arr[a + 2][b] == 0) {
		DFS(c, d, a + 2, b);
		if (arr[a + 1][b + 1] == 0) DFS(c, d, a + 2, b + 1);
	}
}

void Digonal(int a, int b, int c, int d) {
	DFS(c, d, a + 1, b + 2);
	DFS(c, d, a + 2, b + 1);
	if (arr[a + 2][b + 1] == 0 && arr[a + 1][b + 2] == 0) DFS(c, d, a + 2, b + 2);
}

void DFS(int a, int b, int c, int d) {
	if (arr[a][b] == 1 || arr[c][d] == 1) return;
	if ((a == N - 1 && b == N - 1) || (c == N - 1 && d == N - 1)) {
		cnt++;
		return;
	}
	if (a == c) { Width_go(a, b, c, d); }
	else if (b == d) { Height_go(a, b, c, d); }
	else { Digonal(a, b, c, d); }
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
		arr[i][N] = 1;
	}
	for (int i = 0; i < N + 1; i++) {
		arr[N][i] = 1;
	}
	DFS(0, 0, 0, 1);
	cout << cnt;
}