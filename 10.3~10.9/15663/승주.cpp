#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[10];
int ans[10];
int bef[10] = {};
int visit[10] = {};
int visit2[10] = {};

void DFS(int pos, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < cnt; i++) {
			if (ans[i] != bef[i]) { break; }
			if (i == cnt - 1) { return; }
		}
		for (int i = 0; i < cnt; i++) {
			cout << ans[i] << " ";
			bef[i] = ans[i];
		}
		cout << '\n';
	}

	if (pos >= N) { return; }
	if (visit[pos] == 0) {
		visit[pos] = 1;
		int flag = 0;
		if (cnt >= 1 && ans[cnt - 1] == arr[pos]) {
			flag = 1;
		}
		ans[cnt] = arr[pos];
		DFS(0, cnt + 1);
		if (flag == 0) visit[pos] = 0;
	}
	DFS(pos + 1, cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	DFS(0, 0);

}