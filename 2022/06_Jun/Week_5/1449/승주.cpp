#include <iostream>

using namespace std;

int main() {
	int N, L;
	int arr[2002] = {};
	int input;
	int cnt = 0;
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[input] = 1;
	}
	for (int i = 1; i <= 1000; i++) {
		if (arr[i] == 1) {
			cnt++;
			i += L - 1;
		}
	}
	cout << cnt;
}