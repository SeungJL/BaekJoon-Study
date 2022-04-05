#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>


using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, x;
	string str;

	cin >> M;
	int Bit = 0;

	while (M--) {
		cin >> str;
		if (str == "add") {
			cin >> x;
			Bit |= (1 << x);
		}
		else if (str == "remove") {
			cin >> x;
			Bit &= ~(1 << x);
		}
		else if (str == "check") {
			cin >> x;
			if (Bit & (1 << x)) {
				cout << 1;
			}
			else { cout << 0; }
			cout << '\n';
		}
		else if (str == "toggle") {
			cin >> x;
			Bit ^= (1 << x);
		}
		else if (str == "all") {
			Bit = (1 << 21) - 1;
		}
		else {
			Bit = 0;
		}
	}
}