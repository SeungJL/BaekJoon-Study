#include <iostream>
#include <algorithm>

using namespace std;

constexpr int INF = 987654321;
int N, M, ans = 0;
int arr1[101][101], arr2[101][101];
int cnt1[101] = { 0, }, cnt2[101] = { 0, };

void floyd()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (arr1[j][i] != INF && arr1[i][k] != INF)
					arr1[j][k] = min(arr1[j][k], arr1[j][i] + arr1[i][k]);
				if (arr2[j][i] != INF && arr2[i][k] != INF)
					arr2[j][k] = min(arr2[j][k], arr2[j][i] + arr2[i][k]);
			}
		}
	}
}

void init()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr1[i][j] = INF;
			arr2[i][j] = INF;
		}
	}
}

int main(void)
{
	cin >> N >> M;
	init();

	for (int i = 1; i <= M; i++) {
		int x, y;
		cin >> x >> y;
		arr1[x][y] = 1;
		arr2[y][x] = 1;
	}

	floyd();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr1[i][j] != INF)
				cnt1[i]++;
			if (arr2[i][j] != INF)
				cnt2[i]++;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (cnt1[i] >= (N + 1) / 2 || cnt2[i] >= (N + 1) / 2) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}