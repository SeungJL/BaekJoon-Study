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
	deque <pair<int, int>> dq;
	int N;
	cin >> N;
	int x;
	bool check[10001] = {  };
	for (int i = 0; i < N; i++) {
		cin >> x;
		dq.push_back(make_pair(x, i + 1));
	}

	while (1) {
		int a = dq.front().first;

		cout << dq.front().second << " ";
		dq.pop_front();
		if (dq.empty()) { break; }
		if (a > 0) {
			a--;
			while (a--) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			a = -a;
			while (a--) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
}



