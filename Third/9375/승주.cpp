#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>
using namespace std;

int main() {
	int T;
	int n;
	int ans;
	string a, b;
	cin >> T;
	map<string, int>M;

	while (T--) {
		map<string, int>::iterator iter;
		ans = 1;

		cin >> n;

		M.clear();
		while (n--) {
			cin >> a >> b;
			if (M.find(b) != M.end()) {
				M[b]++;
			}
			else {
				M.insert({ b,1 });
			}
		}
		for (iter = M.begin(); iter != M.end(); iter++) {
			ans *= iter->second + 1;
		}
		cout << ans - 1 << endl;
	}


}