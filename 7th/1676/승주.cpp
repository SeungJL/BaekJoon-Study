#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (i % 5 == 0) {
			cnt++;
		}
		if (i % 25 == 0) {
			cnt++;
		}
		if (i % 125 == 0) {
			cnt++;
		}
	}
	cout << cnt;
}