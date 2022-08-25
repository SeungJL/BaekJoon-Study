// BOJ 15664!!

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
int arr[10];
int comb[10];

void dfs_comb(int depth, int visited, int last_i) {
	if (depth == M) {
		for (int i=0; i<M; i++) {
			cout << comb[i] << " ";
		}
		cout << "\n";
		return;
	}

	int prev = 0;
	for (int i=last_i + 1; i<N; i++) {
		if ((visited & (1 << i)) == 0 && prev != arr[i]) {
			comb[depth] = arr[i];
			prev = arr[i];
			dfs_comb(depth + 1, visited | (1 << i), i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	cin >> N >> M;
	for (int i=0; i<N; i++) {
		cin >> arr[i];
	}

	// solve
	sort(arr, arr + N);
	dfs_comb(0, 0, -1);

}