// blog - https://blog.naver.com/hio4662/222932939703

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	/* input */
	int N;
	cin >> N;

	/* solve */
	long dp_2 = 1, dp_1 = 3;
	long cur = dp_1;

	for (int i=2; i<=N; i++) {
		cur = (dp_1 + (dp_2 * 2) + (dp_1 - dp_2)) % 9901;
		dp_2 = dp_1;
		dp_1 = cur;
	}

	/* print answer */
	cout << cur << "\n";
}