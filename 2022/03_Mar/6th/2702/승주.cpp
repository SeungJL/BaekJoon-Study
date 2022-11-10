#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}

	int c = a % b;
	return gcd(b, c);
}

int main() {
	int a, b, T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		int G = gcd(a, b);
		cout << a * b / G << " " << G << endl;

	}
}

