#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, C, W;
	cin >> N >> C >> W;
	vector<int> trees(N);
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
	}
	sort(trees.begin(), trees.end());
	long long int len, sum, temp, value, max_sum = 0;

	for (len = trees[N-1]; len > 0; len--) {		
		sum = 0;
		for (int j = N-1; j >= 0; j--) {		
			if (trees[j] < len)
				break;
			temp = trees[j] / len;
			if (trees[j] % len == 0) {
				value = ((W * len * temp) - ((temp-1) * C));
				if (value > 0) sum += value;
			}
			else {
				value = ((W * len * temp) - (temp * C));
				if (value > 0) sum += value;
			}
		}
		max_sum = max(sum, max_sum);
	}
	cout << max_sum << endl;

	return 0;
}
