#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

/************************** 실패 ************************/

bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
	return a.second < b.second;
}

int combination(int n, int r) {
	if (r > n - r) r = n - r;
	long long res = 1;
	for (int i = 0; i < r; i++) res *= n--;
	for (int i = 0; i < r; i++) res /= r--;
	return res;
}

int main(void) {
	//freopen("input.txt", "rt", stdin);

	char c;
	map<char, int> m;
	while ((c = getchar()) != '\n') {
		if (m.count(c)) m[c]++;
		else m.insert({ c, 1 });
	} // 입력

	vector<pair<char, int>> v(m.begin(), m.end()); // value 정렬을 위해 벡터로 옮김
	sort(v.begin(), v.end(), cmp); // 오름차순 정렬 (갯수가 적은 것부터)

	int ans = 1, n = -1, r;
	for (auto it = v.begin() + 1; it != v.end(); it++) {
		//if (it == v.begin()) continue;
		n += (it - 1)->second;
		r = it->second;
		if (r - 2 > n) {
			ans = 0;
			break;
		}
		else {
			ans *= combination(n, r);
			if (r - n) {
				r = r - n;
				ans *= combination(2, r);
			}
		}
	}
	cout << ans;

	return 0;
}