#include <iostream>

using namespace std;

int arr[11][11] = {};
int teamStat = 0;
int visit[11] = {};

void DFS(int sum, int pos) {
	if (pos == 11) {
		if (teamStat < sum) {
			teamStat = sum;
			return;
		}
	}
	for (int i = 0; i < 11; i++) {
		if (arr[pos][i] == 0) continue;
		if (visit[i] == 1) continue;
		visit[i] = 1;
		sum += arr[pos][i];
		pos++;
		DFS(sum, pos);
		visit[i] = 0;
		pos--;
		sum -= arr[pos][i];
	}
}
int main() {

	int C;
	cin >> C;
	while (C--) {
		teamStat = 0;
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> arr[i][j];
			}
		}
		DFS(0, 0);
		cout << teamStat << endl;
	}

}