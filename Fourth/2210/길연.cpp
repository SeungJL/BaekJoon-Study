// 백준 2210번 

#include <iostream>

using namespace std;
int map[5][5];
int ans = 0;
bool visit[100000];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void DFS(int x, int y, int sum, int cnt) {
	
	if (cnt == 5) { // 5번 다 이동하면 index(sum) 초기화. <- 중복 방지
		if (visit[sum] == false) {
			visit[sum] = true;
			ans++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int px = x + dx[i];
		int py = y + dy[i];
		if (px >= 0 && py >= 0 && px < 5 && py < 5)
			DFS(px, py, sum * 10 + map[px][py], cnt + 1);
			// 이전 수가 10의 자리씩 늘어나니까 *10 해줘야함
	}
}

int  Solution() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			DFS(i, j, map[i][j], 0);
		}
	}
	return ans;
 }

int main(void) {
	// 구할 수 있는 모든 수 다 탐색 -> 완전탐색 

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cin >> map[i][j];
	}

	ans = Solution();
	cout << ans << endl;

	return 0;
}

