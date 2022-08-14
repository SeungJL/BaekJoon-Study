// BOJ 1421

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int N, C, W, input, longest = 0;
	cin >> N >> C >> W;

	vector<int> arr;
	while (N--) {
		cin >> input;
		arr.push_back(input);
		if (input > longest) longest = input;
	}

	long long max_res = 0, res = 0;
	int len = longest, cnt = 0, profit;
	while (len) {
		for (auto wood : arr) {
			cnt = wood / len;
			profit = cnt * len * W;
			profit -= (wood % len == 0) ? (cnt - 1) * C : cnt * C;
			// int cost = (wood - 0.5) / len;
			// profit -= cost * C;
			if (profit > 0) res += profit;
		}
		if (res > max_res) max_res = res;
		res = 0;
		len--;
	}

	cout << max_res << "\n";
}