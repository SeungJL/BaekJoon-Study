#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int> pos;
priority_queue<int, vector<int>, greater<int>> neg;
int d = 0, MAX = 0;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, p;
	// freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> p;
		if (p > 0) {
			pos.push(p);
		}
		else {
			neg.push(p);
		}
	}
	
	if (!pos.empty()) {
		MAX = max(pos.top(), MAX);
	}
	if (!neg.empty()) {
		MAX = max(neg.top() * -1, MAX);
	}

	while (!pos.empty()) {
		int tmp = pos.top();
		for (int i = 0; i < M; i++) {
			pos.pop();
			if (pos.empty()) break;
		}
		d += tmp * 2;
	}

	while (!neg.empty()) {
		int tmp = neg.top() * -1;
		for (int i = 0; i < M; i++) {
			neg.pop();
			if (neg.empty()) break;
		}
		d += tmp * 2;
	}
	d -= MAX;
	cout << d;

	return 0;
}