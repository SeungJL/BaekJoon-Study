#include <iostream>
#include <algorithm>

using namespace std;
int arr[1025][1025] = {};

int secondMax(int a, int b, int c, int d) {
	int arr[4] = { a,b,c,d };
	sort(arr, arr + 4);
	return arr[2];
}

int devideConquer(int totalSize) {
	if (totalSize == 1) { cout << arr[0][0]; return 0; }

	for (int i = 0; i < totalSize / 2; i++) {
		for (int j = 0; j < totalSize / 2; j++) {
			int a = i * 2;
			int b = j * 2;
			arr[i][j] = secondMax(arr[a][b], arr[a + 1][b], arr[a][b + 1], arr[a + 1][b + 1]);
		}
	}
	return devideConquer(totalSize / 2);
}

int main() {
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	devideConquer(N);
}