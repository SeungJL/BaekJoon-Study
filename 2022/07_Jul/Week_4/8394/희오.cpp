// BOJ 8394 약수

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	// freopen("input.txt", "rt", stdin);

	int n;
	cin >> n;

	int fib_n_1, fib_n_2;
	fib_n_2 = 1;
	fib_n_1 = 2;
	
	if (n < 3) {
		cout << ((n==1) ? fib_n_2 : fib_n_1) << "\n";
		return 0;
	}
	for (int i=3; i<n; i++) {
		int tmp = fib_n_1;
		fib_n_1 = (fib_n_1 + fib_n_2) % 10;
		fib_n_2 = tmp;
	}
	cout << (fib_n_1 + fib_n_2) % 10 << "\n";
}