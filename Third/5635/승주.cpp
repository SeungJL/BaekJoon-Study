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
	int n;
	string name;
	string a, b, c;
	string str;
	vector <pair<int, string>> V;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> name >> a >> b >> c;
		if (b.size() == 1) {
			b = "0" + b;
		}
		if (a.size() == 1) {
			a = "0" + a;
		}
		str = c + b + a;
		V.push_back(make_pair(stoi(str), name));
	}
	sort(V.begin(), V.end());
	cout << V.back().second << endl;
	cout << V.front().second;
}