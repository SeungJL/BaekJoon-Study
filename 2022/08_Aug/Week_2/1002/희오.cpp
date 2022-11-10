// BOJ 1002

#include <iostream>

using namespace std;

unsigned int my_pow(int x) {
	return x * x;
}

unsigned int get_d_square(int x1, int y1, int x2, int y2) {
	return my_pow(x1 - x2) + my_pow(y1 - y2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int TC;
	cin >>TC;

	while (TC--) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		unsigned int d, r_sum, r_diff;
		d = get_d_square(x1, y1, x2, y2);
		r_sum = my_pow(r1 + r2);
		r_diff = my_pow(r1 - r2);

		if (d == 0 && r1 == r2) {
			cout << "-1\n";
		}
		else if (r_sum < d || r_diff > d || d == 0) {
			cout << "0\n";
		}
		else if (r_sum == d || r_diff == d) {
			cout << "1\n";
		}
		else if (r_diff < d && d < r_sum) {
			cout << "2\n";
		}
	}
}