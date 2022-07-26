#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int left_prev;
	int left_now;
	int false_prev;
	int false_now;
	
	left_now = 0;
	false_now = 1;
	for (int i = 2; i <= n; i++) {
		left_prev = left_now;
		false_prev = false_now;
		left_now = false_prev % 10;
		false_now = (false_prev + left_prev) % 10;
	}

	cout << (left_now + false_now) % 10 << endl;
	return 0;
}
