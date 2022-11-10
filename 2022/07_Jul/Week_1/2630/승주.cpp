#include <iostream>

using namespace std;
bool A[128][128];
int white = 0, blue = 0;


void square(int x, int y, int length) {
	int h = 0;
	int m = 0, n = 0;
	for (int i = 0; i < length; i++) {
		if (h == 1) {
			break;
		}
		for (int j = 0; j < length; j++) {
			if (m == 0) {
				if (A[x + i][y + j] == 0) {
					n = 1;
					if (i == length - 1 && j == length - 1) {
						white++;
						return;
					}
				}
				else if (n == 1) {
					h = 1;
					break;
				}


			}
			if (n == 0) {
				if (A[x + i][y + j] == 1) {
					m = 1;
					if (i == length - 1 && j == length - 1) {
						blue++;
						return;
					}
				}
				else if (m == 1) {
					h = 1;
					break;
				}

			}
		}
	}

	int after = length / 2;
	square(x, y, after);
	square(x, y + after, after);
	square(x + after, y, after);
	square(x + after, y + after, after);
}


int main() {
	int N;


	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	square(0, 0, N);
	cout << white << endl << blue;

}