#include <iostream>
#include <map>
using namespace std;
map<long long, long long> d;
const long long mod = 1000000000LL;
long long fibo(long long n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 1;
	}
	else if (d.count(n) > 0) {
		return d[n];
	}
	else {
		if (n % 2 == 1) {
			long long m = (n + 1) / 2;
			long long t1 = fibo(m);
			long long t2 = fibo(m - 1);
			d[n] = t1 * t1 + t2 * t2;
			d[n] %= mod;
			return d[n];
		}
		else {
			long long m = n / 2;
			long long t1 = fibo(m - 1);
			long long t2 = fibo(m);
			d[n] = (2LL * t1 + t2)*t2;
			d[n] %= mod;
			return d[n];
		}
	}
}
int main() {
	long long n;
	cin >> n;
	if (n < 0 && (n * -1) % 2 != 0) {
		cout << 1 << '\n';
		cout << fibo(-1 * n);
	}
	else if (n < 0 && (n * -1) % 2 == 0) {
		cout << -1 << '\n';
		cout << fibo(-1 * n);

	}
	else if (n == 0) {
		cout << 0 << '\n' << 0;
	}
	else {
		cout << 1 << '\n' << fibo(n);
	}
	return 0;
}