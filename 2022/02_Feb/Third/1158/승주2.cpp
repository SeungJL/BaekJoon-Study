#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
	int K, N;
	cin >> K >> N;
	queue <int> q;
	cout << '<';

	for (int i = 1; i <= K; i++) {
		q.push(i);
	}
	int cnt = 0;
	while (1) {
		cnt++;
		if (cnt == N) {
			if (q.size() == 1) {
				cout << q.front() << '>';
				break;
			}
			cout << q.front() << ',' << " ";
			q.pop();
			cnt = 0;
			continue;
		}
		q.push(q.front());
		q.pop();
	}


}