#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

/************************** ���� ************************/

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
	} // �Է�

	vector<pair<char, int>> v(m.begin(), m.end()); // value ������ ���� ���ͷ� �ű�
	sort(v.begin(), v.end(), cmp); // �������� ���� (������ ���� �ͺ���)

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