#include <iostream>
#include <vector>

using namespace std;

int dp[17];
vector<pair<int,int>> info(17);

int getMax(int index) {
	if (dp[index] != 0) return dp[index];

	int maxPrice = 0;
	for (int i = 1; i < index; i++) {
		if (i + info[i].first <= index) {
			maxPrice = max(maxPrice, getMax(i) + info[i].second);
		}
	}
	return dp[index] = maxPrice;
}

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int t, p;
		cin >> t >> p;
		info[i].first = t;
		info[i].second = p;
	}

	cout << getMax(N+1) << endl;

	return 0;
}