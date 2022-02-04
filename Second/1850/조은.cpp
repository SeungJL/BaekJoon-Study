#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long GCD(long long a, long long b) {
	if (a < b) {
		long long temp = a;
		a = b;
		b = temp;
	}
	if (a % b == 0) { return b; }
	else { return GCD(b, a % b); }
}

int main() {
	//freopen("input.txt", "rt", stdin);
	long long A, B;
	cin >> A >> B;

	long long gcd = GCD(A, B);
	for (long long i = 0; i < gcd; i++) {
		cout << 1;
	}
	return 0;
}
