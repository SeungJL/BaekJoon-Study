#include <iostream>
#include <algorithm>

#define INF 987654321
using namespace std;

int n, a, b, m;	//전체 사람의 수, 촌수를 계산해야 하는 서로 다른 두 사람의 번호, 관계의 개수
int arr[101][101];

void floyd_warshall()	//플로이드 워셜 알고리즘
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (arr[j][i] != INF && arr[i][k] != INF)
					arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}
}

int main(void)
{
	cin >> n >> a >> b >> m;	//입력

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;
		}
	}

	while (m--) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	floyd_warshall();

	if (arr[a][b] == INF)	//친척 관계가 전혀 없는 촌수
		cout << -1;
	else
		cout << arr[a][b];

	return 0;
}