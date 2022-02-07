// 백준 13241번
// 2022년 02월 06일

#include <iostream>

using namespace std;


long long int gcd(long long a, long long b) {

	long long int tmp;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	if (b == 0)
		return a;
	
	return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main() {

	long long int  a, b;

	cin >> a >> b;

	cout << lcm(a, b);

	return 0;
}
