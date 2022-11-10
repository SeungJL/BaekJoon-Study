#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, x1, y1, r1, x2, y2, r2;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double distance = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
		if (x1 == x2 && y1 == y2) {		
			if (r1 == r2)
				cout << -1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (distance + min(r1, r2) < max(r1, r2)) {		
			cout << 0 << '\n';
		}
		else if (distance + min(r1, r2) == max(r1, r2)) {		
			cout << 1 << '\n';
		}
		else {	
			if (distance > r1+r2)
				cout << 0 << '\n';
			else if (distance == r1+ r2)
				cout << 1 << '\n';
			else
				cout << 2 << '\n';
		}
	}

	return 0;
}
