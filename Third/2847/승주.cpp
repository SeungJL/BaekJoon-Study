#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
	int N;
	int list[101] = {};
	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	int Min = list[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		if (list[i] <= Min - 1) {
			Min = list[i];
		}
		else {
			Min -= 1;
			cnt += list[i] - Min;
		}
	}
	cout << cnt;

}