#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

bool isPrimeNum(int n) {
	if (n <= 1) { return false; }
	else if (n % 2 == 0) { return n == 2 ? true : false; }
	else {
		for (int i = 3; i <= (int)sqrt(n); i += 2) {
			if (n % i == 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int T;
	cin >> T;
	int* n = new int[T];
	int a = 2, b;
	for (int i = 0; i < T; i++) {
		cin >> n[i];
		for (int j = n[i] / 2; j >= 2; j--) {
			a = j;
			b = n[i] - j;
			if (isPrimeNum(a)) {
				if (isPrimeNum(b)) {
					cout << a << ' ' << b << endl;
					break;
				}
			}
		}
	}

	return 0;
}
