#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int N, S, M;
int vol[51];
int ans = 0;
int Max = -1;
int totalSum[51];
int total = 0;

void DFS(int sum, int pos) {
	if (sum > M || sum < 0) return;
	if (pos == N) {
		if (sum > Max) { Max = sum; }
		return;
	}
	if (sum + total - totalSum[pos - 1] <= Max)
		return;
	int value = vol[pos];
	DFS(sum + value, pos + 1);
	DFS(sum - value, pos + 1);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> S >> M;
	int temp;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		vol[i] = temp;
		total += temp;
		totalSum[i] = total;
	}

	DFS(S, 0);
	cout << Max;
}