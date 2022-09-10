#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check_if_prefix(string a, string b) {
	for (int i=0; i<a.length(); i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int TC;
	cin >> TC;

	while (TC--) {
		int n;
		vector<string> list;

		cin >> n;
		while (n--) {
			string input;
			cin >> input;
			list.push_back(input);
		}
		
		bool isConsistant = true;

		sort(list.begin(), list.end());

		for(auto it = list.begin(); it<list.end()-1; it++) {
			if (check_if_prefix(*it, *(it+1))) {
				isConsistant = false;
				break;
			}
		}

		(isConsistant) ? cout << "YES\n" : cout << "NO\n";
	}
}