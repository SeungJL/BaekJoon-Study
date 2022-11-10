#include <iostream>

using namespace std;

int main() {
	int N, M;
	int arr[102][102] = { 0 };
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] - arr[i - 1][j] > 0) {
				sum += arr[i][j] - arr[i - 1][j];
			}
			if (arr[i][j] - arr[i + 1][j] > 0) {
				sum += arr[i][j] - arr[i + 1][j];
			}
			if (arr[i][j] - arr[i][j + 1] > 0) {
				sum += arr[i][j] - arr[i][j + 1];
			}
			if (arr[i][j] - arr[i][j - 1] > 0) {
				sum += arr[i][j] - arr[i][j - 1];
			}
		}
	}
	cout << sum + 2 * N * M;

}