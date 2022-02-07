#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
	string name;
	int d, m, y;
}birthday;

bool cmp(const birthday &a, const birthday &b) {
	// 나이 내림차순
	if (a.y == b.y) {
		if (a.m == b.m) {
			return a.d < b.d;
		}
		else { return a.m < b.m; }
	}
	else { return a.y < b.y; }
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	vector<birthday> v;
	for (int i = 0; i < n; i++) {
		string s;
		int x, y, z;
		cin >> s >> x >> y >> z;
		v.push_back({ s,x,y,z });
	}

	sort(v.begin(), v.end(), cmp);
	
	cout << v.back().name << endl << v.front().name;

	return 0;
}
