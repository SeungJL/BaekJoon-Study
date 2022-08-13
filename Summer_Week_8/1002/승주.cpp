#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int x1, y1, x2, y2;
	int r1, r2;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

		if (dis == 0) {
			if (r1 == r2) { cout << -1 << endl; }
			else { cout << 0 << endl; }
			continue;
		}

		if (dis > r1 + r2) { cout << 0 << endl; }
		else if (dis == r1 + r2) { cout << 1 << endl; }
		else if (abs(r1 - r2) < dis && dis < r1 + r2) { cout << 2 << endl; }
		else if (abs(r1 - r2) == dis) { cout << 1 << endl; }
		else if (dis < abs(r1 - r2)) { cout << 0 << endl; }
	}
}