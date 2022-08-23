#include <iostream>
#include <cmath>	

using namespace std;
long fibo[1000001];
int mark[1000001];		//1 or -1

int main() {
	int n;
	cin >> n;
	if (n >= 2) {
		fibo[0] = 0;
		fibo[1] = 1;
		for (int i = 2; i <= n; i++) {
			fibo[i] = (fibo[i-1] + fibo[i-2]) % 1000000000;
		}
		cout << 1 << '\n' << fibo[n] << endl;
	}
	else if (n == 1) {
		cout << 1 << '\n' << 1 << endl;
	}
	else if (n == 0) {
		cout << 0 << '\n' << 0 << endl;
	}
	else if (n == -1) {
		cout << 1 << '\n' << 1 << endl;
	}
	else {
		fibo[0] = 0;
		mark[0]	= 1;
		fibo[1] = 1;
		mark[1] = 1;
		long temp;
		n = abs(n);
		for (int i = 2; i <= n; i++) {
			temp = (mark[i-2]*fibo[i-2]) % 1000000000 - (mark[i-1]*fibo[i-1]) % 1000000000;
			if (temp >= 0) mark[i] = 1;
			else mark[i] = -1;
			fibo[i] = abs(temp) % 1000000000;
		}
		cout << mark[n]	<< '\n' << fibo[n] << endl;
	}

	return 0;
}