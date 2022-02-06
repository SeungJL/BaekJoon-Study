#include <iostream>

using namespace std;

long long int a, b;

long long int findLCM(long long int x, long long int y) {
	if (x >= y) {
		if (x % y == 0) return x;
		else return findLCM(x, y+b);
	}	
	else {
		if (y % x == 0) return y;
		else return findLCM(x+a, y);
	}
}

int main() {
	cin >> a >> b;
	cout << findLCM(a, b) << endl;

	return 0;
}