#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <map>

using namespace std;

int main() {
	iostream::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m, n;
	cin >> m >> n;
	vector <int> A;
	vector <int> B;
	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;
		A.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		cin >> x;
		B.push_back(x);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int i, j;
	i = j = 0;
	int cnt = 1;
	int flag_A = 0;
	int flag_B = 0;
	int h = 0;
	int q = 0;
	while (1) {

		cnt++;
		if (A[i] > B[j]) {
			if (flag_B == 1) {
				i++;
			}
			else {
				j++;
			}
			h = 0;

		}
		else if (A[i] < B[j]) {
			if (flag_A == 1) { j++; }
			else { i++; }
			h = 0;
		}
		else if (A[i] == B[j]) {
			if (flag_A == 1) { j++; }
			else if (flag_B == 1) { i++; }
			else {
				int p = i;
				int q = j;
				while (1) {
					if (p >= m - 1) { p--; }
					if (q >= n - 1) { q--; }
					if (A[p + 1] > B[q + 1]) { j++; break; }
					else if (A[p + 1] < B[q + 1]) { i++; break; }
					else { p++; q++; }
				}
			}
			if (h == 0) {
				cnt -= 2;
				h = 1;
			}
			else {
				cnt--;
			}
		}

		if (q == 1) { break; }
		if (i > m - 1) { i--; }
		if (j > n - 1) { j--; }
		if (i == m - 1) {
			flag_A = 1;
		}
		else if (j == n - 1) { flag_B = 1; }
		if (i >= m - 1 && j >= n - 1) {
			q = 1;
		}
	}
	if (m == n) {
		if (cnt == 1) {
			cout << 0;
			return 0;
		}
	}
	cout << cnt;
}



