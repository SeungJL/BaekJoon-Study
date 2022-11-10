#include <iostream>

using namespace std;


int arr[10][101] = {};

int DP(int first, int length) {

	if (arr[first][length] != 0) { return arr[first][length]; }
	if (first == 0) { return DP(1, length - 1); }
	if (first == 9) { return DP(8, length - 1); }
	return arr[first][length] = (DP(first - 1, length - 1) + DP(first + 1, length - 1)) % 1000000000;

}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i <= 9; i++) {
		arr[i][1] = 1;
	}
	int sum = 0;
	for (int i = 1; i <= 9; i++) {
		sum += DP(i, N);
		if (sum > 1000000000) {
			sum %= 1000000000;
		}
	}
	cout << sum;
}