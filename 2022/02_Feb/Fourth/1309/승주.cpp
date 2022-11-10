#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <cmath>

using namespace std;
int main() {
	int N;
	cin >> N;

	int a = 1;
	int b = 3;
	int c;
	if (N == 1) {
		cout << b;
		return 0;
	}
	int h = 0;
	for (int i = 0; i < N - 1; i++) {
		if (a >= 9901) {
			a %= 9901;
			b %= 9901;
		}
		c = b * 2 + a;

		a = b;
		b = c;
	}
	cout << c % 9901;
}