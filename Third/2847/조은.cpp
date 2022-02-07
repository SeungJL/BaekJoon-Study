#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	int N;
	cin >> N;
	vector<int> v;
	while (N--) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	
	int cnt = 0;
	for (int i = v.size() - 1; i > 0; i--) {
		while (v[i] <= v[i - 1]) {
			v[i - 1]--;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}
