#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {

	iostream::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long a, b;
	long long left = 0;
	long long right = 0;
	cin >> a >> b;
	if (a == 1 && b != 1) {
		cout << 0 << " " << b - 1;
		return 0;
	}
	else if (a != 1 && b == 1) {
		cout << a - 1 << " " << b - 1;
		return 0;
	}
	while (1) {
		if (a > b) {
			a -= b;
			left++;
			continue;
		}
		else if (a < b) {
			b -= a;
			right++;
			continue;
		}
		else {
			cout << left << " " << right;
			return 0;
		}

	}
}
