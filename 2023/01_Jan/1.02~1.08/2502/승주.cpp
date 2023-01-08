#include <iostream>

using namespace std;

int main() {
	int D, K;
	cin >> D >> K;
	int a = 1, b = 1;
	int temp;
	for (int i = 0; i < D - 3; i++) {
		temp = a;
		a = b;
		b = temp + b;
	}
	int i = 1;
	while (i++) {
		if ((K - a * i) % b == 0) {
			cout << i << endl;
			cout << (K - a * i) / b << endl;
			break;
		}
	}
}