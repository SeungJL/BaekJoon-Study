#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <cstring>
#include <cmath>
#include <deque>

using namespace std;
int main() {
	iostream::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	int x;
	long long y, z;
	bool check[100001];
	deque <long long> dq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			check[i] = 0;
		}
		else {
			check[i] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> y;
		if (check[i] == 0) {
			dq.push_front(y);
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> z;
		if (dq.empty() == 1) {
			cout << z << " ";
			continue;
		}
		cout << dq.front() << " ";
		dq.pop_front();
		dq.push_back(z);
	}

}
