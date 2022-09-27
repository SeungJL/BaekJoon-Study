#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;
	while (t > 0) {

		cin >> n;
		vector<int> input(n);
		for (int i = 0; i < n; i++) {
			cin >> input[i];
		}

		sort(input.begin(), input.end());
	
		vector<int> height(n);
		int k = 0;
		for (int i = 0; i < input.size()-1; i+=2) {
			height[k] = input[i];
			height[n - k - 1] = input[i + 1];
			k++;
		}
		if (input.size() % 2 == 1)	height[input.size() / 2] = input[n - 1];

		int answer = abs(height[0] - height[n - 1]);

		for (int i = 0; i < input.size()-1; i++) {
			answer = max(answer,abs(height[i] - height[i + 1]));
		}
		cout << answer << "\n";
		t--;
	}
}
