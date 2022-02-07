#include <iostream>
#include <cmath>
using namespace std;

int sosu(int k) {
	int h = sqrt(k);

	if (k == 1)
		return 0;
	if (k == 2 || k == 3) {
		return 1;
	}
	for (int i = 2; i <= h; i++) {
		if (k % i == 0) {
			return 0;
		}
		if (i == h) {
			return 1;
		}
	}

}



int main() {
	int T, n, a, b;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		a = n / 2;
		b = n / 2;
		int j = 0;

		while (1) {
			if (sosu(a - j) == 1 && sosu(b + j) == 1) {
				cout << a - j << " " << b + j << endl;
				break;
			}
			j++;
		}
	}

}