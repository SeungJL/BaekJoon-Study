#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	int N;
	cin >> N;
	map<string, int, greater<string>> m;
	string s;
	while (N--) {
		cin >> s;
		if (m.count(s)) {
			m.find(s)->second += 1;
		}
		else {
			m.insert({ s,1 });
		}
	}

	int max_value = -1;
	string max_key;
	for (auto i = m.begin(); i != m.end(); i++) {
		int t_max = max(max_value, i->second);
		if (t_max == i->second) {
			max_value = t_max;
			max_key = i->first;
		}
	}
	cout << max_key;

	return 0;
}
