#include <iostream>
#include <cmath>
using namespace std;

int N;
int visit[22] = {};
int arr[22][22];
int Min = 10000000;
int FindCheck;

int ValueCompare() {
	int left = 0;
	int right = 0;
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 1) {
			for (int j = i + 1; j <= N; j++) {
				if (visit[j] == 1) {
					left += arr[i][j] + arr[j][i];
				}
			}
		}
		else {
			for (int j = i + 1; j <= N; j++) {
				if (visit[j] == 0) {
					right += arr[i][j] + arr[j][i];
				}
			}
		}
	}
	return abs(left - right);
}

void DFS(int count, int Num) {
	if (count == FindCheck) {
		int ans = ValueCompare();
		if (ans < Min) Min = ans;
		return;
	}
	if (Num > N) { return; }
	DFS(count, Num + 1);
	visit[Num] = 1;
	DFS(count + 1, Num + 1);
	visit[Num] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}
	for (int i = 2; i <= N; i++) {
		FindCheck = i;
		DFS(0, 1);
	}
	cout << Min;
}