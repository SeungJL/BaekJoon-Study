// 11497

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int TC;
	cin >> TC;
	while (TC--) {
        /* input */
		int N;
		cin >> N;
		
		int arr[N];
		for (int i=0; i<N; i++) cin >> arr[i];

        /* solve */
		sort(arr, arr + N);
		
		int diff;       // 인접한 통나무의 높이 차
        int max_diff;   // 통나무 건너뛰기의 난이도, 인접한 통나무 간의 높이 차의 최댓값
		max_diff = arr[1] - arr[0]; // 첫 번째 통나무와 마지막 통나무의 높이 차
		for (int i=0; i<N-2; i++) {
			diff = arr[i+2] - arr[i];
			if (diff > max_diff) max_diff = diff;
		}
		diff = arr[N-1] - arr[N-2]; // 가운데 오게 되는, 가장 높은 통나무 두 개의 높이 차
		if (diff > max_diff) max_diff = diff;

		cout << max_diff << "\n";
	}
}