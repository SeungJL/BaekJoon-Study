#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


int main() {
	int w, h, x, y, t;
	int a, b;

	cin >> w >> h >> x >> y >> t;
	a = t % (2 * w);
	b = t % (2 * h);

	if (a < w - x) { x = x + a; }
	else if (a < 2 * w - x) { x = 2 * w - a - x; }
	else { x = x - 2 * w + a; }

	if (b < h - y) { y = y + b; }
	else if (b < 2 * h - y) { y = 2 * h - b - y; }
	else { y = y - 2 * h + b; }

	cout << x << ' ' << y;
}