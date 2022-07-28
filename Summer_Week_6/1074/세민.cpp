#include <iostream>

using namespace std;

int N, r, c;

int solve(int n, int row, int col) {
	if (n == 0) {
		return 0;
	}
	return 2 * (row % 2) + (col % 2) + 4 * solve(n - 1, row / 2, col / 2);
}

int main(void)
{
	cin >> N >> r >> c;
	cout << solve(N, r, c);

	return 0;
}