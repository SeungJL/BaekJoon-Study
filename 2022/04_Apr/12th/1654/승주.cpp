#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


int main() {
	int K, N;
	long long x;
	long long arr[10001];
	vector <long long> V;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + K);
	long long start = 0;
	long long end = arr[K - 1];
	long long middle;
	while (1) {
		if (start > end) { break; }
		middle = (start + end) / 2;

		if (middle == 0) {
			middle = 1;
		}
		long long cnt = 0;
		for (int i = 0; i < K; i++) {
			cnt += arr[i] / middle;
		}
		if (cnt >= N) {
			V.push_back(middle);
			start = middle + 1;
		}
		else {
			end = middle - 1;
		}
	}
	sort(V.begin(), V.end(), greater<>());
	cout << V.front();
}