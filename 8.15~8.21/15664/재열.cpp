#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<int> nums;
vector<string> results;

void search(string& str, int now_idx, int depth) {
	if (depth == M) {
		if (str.length() == M) {
			if (find(results.begin(), results.end(), str) == results.end())
				results.push_back(str);
		}
	}
	else {
		for (int i = now_idx; i < N; i++) {
			str += (nums[i] + '0');
			search(str, i+1, depth+1);
			str.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	cin >> N >> M;
	nums.resize(N);
	for (int i = 0; i < N; i++) 
		cin >> nums[i];
	sort(nums.begin(), nums.end());
	string str = "";
	search(str, 0, 0);
	
	for (int i = 0; i < results.size(); i++) {
		for (int j = 0; j < results[i].length(); j++) {
			cout << results[i][j] - '0' << ' ';
		}
		cout << '\n';
	}

	return 0;
}