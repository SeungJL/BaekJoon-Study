#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int map[11][11];
bool visited[11][11];
int ans = 987654321;

void solve(int cnt) {
	if (cnt == 3) {
		int tmp = 0;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (visited[i][j]) {
					tmp += map[i][j];
				}
			}
		}
		ans = min(tmp, ans);
		return;
	}

	for (int i = 2; i < N; ++i) {
		for (int j = 2; j < N; ++j) {
			if (visited[i - 1][j] || visited[i][j - 1] || visited[i][j] || visited[i + 1][j] || visited[i][j + 1]) continue;

			visited[i][j] = true;
			visited[i - 1][j] = true;
			visited[i][j - 1] = true;
			visited[i + 1][j] = true;
			visited[i][j + 1] = true;
			solve(cnt + 1);
			visited[i][j] = false;
			visited[i - 1][j] = false;
			visited[i][j - 1] = false;
			visited[i + 1][j] = false;
			visited[i][j + 1] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> map[i][j];
		}
	}
	solve(0);
	cout << ans;
	return 0;
}