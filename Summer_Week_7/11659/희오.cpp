// BOJ 11659

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);
	
	int N, M;
	cin >> N >> M;

	vector<int> sum_arr(N+1, 0);
	for(int i=1; i<=N; i++) {
		cin >> sum_arr[i];
		sum_arr[i] += sum_arr[i-1];
	}

	int i, j;
	while (M--) {
		cin >> i >> j;
		cout << sum_arr[j] - sum_arr[i-1] << "\n";
	}
} 