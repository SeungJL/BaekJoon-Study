#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int result;
	if (n == 3) result = 0;
	else {
		result = 1;
		for (int i = n; i > n-4; i--) {
			result *= i;
		}
		result /= 24;
	}

	cout << result << endl;
	return 0;
}