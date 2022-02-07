#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long GCD(long long a, long long b) {
	if (a % b == 0) { return b; }
	else { return GCD(b, a % b); }
}

long long LCM(long long a, long long b) {
	return a * b / GCD(a, b);
}

int main() {
	//freopen("input.txt", "rt", stdin);
	long long A, B;
	cin >> A >> B;
	
	long long lcm = LCM(A, B);
	cout << lcm;

	return 0;
}
