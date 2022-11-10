// 백준 1026번 보물

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> a;
vector<int> b;
int n;

int minSum() {
	sort(a.begin(), a.end(), greater<>()); // 내림차순
	sort(b.begin(), b.end()); // 오름차순

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += (a[i] * b[i]);

	return ans;
}

int main() {

	cin >> n;
	int v;

	for (int i = 0; i < n; i++) {
		cin >> v;
		a.push_back(v);
	}
	for (int i = 0; i < n; i++) {
		cin >> v;
		b.push_back(v);
	}

	cout << minSum() << endl;

	return 0;
}
