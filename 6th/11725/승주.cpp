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
	int N;
	cin >> N;

	queue <pair<int, int>> q;
	queue <int> next;
	vector <pair<int, int>> ans;
	int a;
	int b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		q.push(make_pair(a, b));
	}
	next.push(1);

	int finding = 0;
	while (1) {
		if (q.empty() == 1) {
			break;
		}
		int cnt = next.size();
		for (int i = 0; i < cnt; i++) {
			finding = next.front();
			next.pop();
			int cnt2 = q.size();
			for (int j = 0; j < cnt2; j++) {
				if (q.front().first == finding) {
					next.push(q.front().second);
					ans.push_back(make_pair(q.front().first, q.front().second));
					q.pop();
				}
				else if (q.front().second == finding) {
					next.push(q.front().first);
					ans.push_back(make_pair(q.front().second, q.front().first));
					q.pop();
				}
				else {
					q.push(q.front());
					q.pop();
				}

			}
		}
	}
	int j = 2;
	while (1) {
		if (j == N + 1) { break; }
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i].second == j) {
				cout << ans[i].first << '\n';
			}
		}
		j++;
	}
}



