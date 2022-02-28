#include <iostream>
#include <set>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int t;
	set<int> set;
	for (int i = 0; i < n + m; i++) {
		cin >> t;
		if (set.count(t)) {
			set.erase(t);
		}
		else set.insert(t);
	}

	cout << set.size();

	return 0;
}