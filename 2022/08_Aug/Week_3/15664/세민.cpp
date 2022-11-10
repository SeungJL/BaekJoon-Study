#include <iostream>
#include <algorithm>

using namespace std;

int arr[8] = {};
int visit[8] = {};
int N, M, cnt = 0;

void Print() {
	for (int i = 0; i < M; i++) {
		cout << visit[i] << " ";
	}
	cout << '\n';
}

void DFS(int idx, int cnt)
{
	if (cnt == M) {
		Print();
		return;
	}

	for (int i = idx; i < N; i++) {
		if (arr[i] == arr[i - 1] && i != idx) continue;
		visit[cnt] = arr[i];
		DFS(i + 1, cnt + 1);
	}
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	DFS(0, 0);
	return 0;
}