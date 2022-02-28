#include <iostream>
using namespace std;

int gcd(int a, int b) {
	int r = a%b;
	return r ? gcd(b,r) : b;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--) {
		int a, b;
		cin >> a >> b;
		cout << lcm(a,b) << ' ' << gcd(a,b) << '\n';
	}

	return 0;
}