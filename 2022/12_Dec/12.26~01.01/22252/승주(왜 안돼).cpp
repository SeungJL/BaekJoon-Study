#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int Q, query;
	map <string, vector<int>> m;
	cin >> Q;
	string name;
	long long ans = 0;
	for (int i = 0; i < Q; i++) {
		cin >> query >> name;
		int count = 0;
		if (query == 1) {
			cin >> count;
			vector <int> temp;
			int tmp = 0;
			for (int j = 0; j < count; j++) {
				cin >> tmp;
				temp.push_back(tmp);
			}
			if (m.find(name) != m.end()) {
				for (int j = 0; j < m[name].size(); j++) {
					temp.push_back(m[name][j]);
				}
				sort(temp.begin(), temp.end(), greater<>());
				m.erase(name);
			}
			else {
				sort(temp.begin(), temp.end(), greater<>());
			}
			m.insert({ name,temp });
		}
		else {
			cin >> count;
			if (m.find(name) == m.end()) continue;
			if (m[name].size() == 0) break;
			for (int j = 0; j < count; j++) {
				sort(m[name].begin(), m[name].end());
				ans += m[name].back();
				m[name].pop_back();
				if (m[name].size() != 0) {
					sort(m[name].begin(), m[name].end(), greater<>());
				}
				else {
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}