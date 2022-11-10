#include <iostream>

using namespace std;

char arr[102][102] = {};
int visit[102][102] = {};
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void DFS(int a, int b, char c, int* cnt) {
	if (arr[a][b] == c && visit[a][b] == 0) {
		(*cnt)++;
		visit[a][b] = 1;
	}
	else { return; }
	for (int i = 0; i < 4; i++) {
		DFS(a + dx[i], b + dy[i], c, cnt);
	}
}

int main() {
	int n, m;
	int Wsum = 0;
	int Bsum = 0;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j] == 0) {
				int cnt = 0;
				DFS(i, j, arr[i][j], &cnt);
				if (arr[i][j] == 'W') { Wsum += cnt * cnt; }
				else { Bsum += cnt * cnt; }
			}
		}
	}
	cout << Wsum << " " << Bsum;
}