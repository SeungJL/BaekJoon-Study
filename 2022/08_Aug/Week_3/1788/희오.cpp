// BOJ 1788

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int n, abs_n;
	cin >> n;
	abs_n = (n >= 0) ? n : 0 - n;

	if (abs_n == 0 || abs_n == 1) {
		cout << abs_n << "\n" << abs_n << "\n";
		return 0;
	}

	unsigned int fibo_n_1 = 1, fibo_n_2 = 0, fibo_n;
	for (int i=2; i<=abs_n; i++) {
		fibo_n = (fibo_n_1 + fibo_n_2) % 1000000000;
		fibo_n_2 = fibo_n_1;
		fibo_n_1 = fibo_n;
	}

	if (n > 0 || (n < 0 && abs_n % 2 == 1)) cout << "1\n";
	else cout << "-1\n";
	cout << fibo_n << "\n";
}