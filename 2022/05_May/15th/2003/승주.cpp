#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, M;
	int arr[10001];

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}


	int start = 0;
	int end = 0;
	int sum = arr[0];
	int cnt = 0;
	while (end < N) {

		if (sum == M) {
			cnt++;
		}
		if (sum < M) {

			sum += arr[++end];
		}
		else {
			sum -= arr[start++];
		}

	}
	cout << cnt;
}