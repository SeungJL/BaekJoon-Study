#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << '<';
	while (!q.empty()) {
		int temp;
		for (int i = 0; i < k-1; i++) {
			temp = q.front();
			q.pop();
			q.push(temp);
		}
		cout << q.front();
		q.pop();
		if (!q.empty()) cout << ',' << ' ';
	}
	cout << '>' << endl;

	return 0;
}