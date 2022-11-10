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
	double N;
	cin >> N;
	double ans = 1;
	for (int i = 1; i <= 4; i++) {
		ans *= N / (double)i;
		N--;
	}
	cout << (int)ans;
}