#include <iostream>

using namespace std;

int arr[3000][3000];
int one = 0, zero = 0, Minus = 0;

void divideConQ(int x, int y, int size) {
	int temp = arr[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (temp != arr[i][j]) {
				for (int k = 0; k < 3; k++) {
					for (int m = 0; m < 3; m++) {
						divideConQ(x + size / 3 * k, y + size / 3 * m, size / 3);
					}
				}
				return;
			}
			temp = arr[i][j];

		}
	}

	if (temp == -1) Minus++;
	else if (temp == 0) zero++;
	else one++;

}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	divideConQ(0, 0, N);

	cout << Minus << endl << zero << endl << one;
}