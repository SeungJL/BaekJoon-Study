#include <iostream>
using namespace std;

int main() {
	int w, h, p, q, t;
	cin >> w >> h >> p >> q >> t;

	int tmp = t;
	int dx=1;
	while(tmp--) {
		if(p==w || p==0) {
			dx = -dx;
			tmp %= 2*w;
		}
		p += dx;
	}

	tmp = t;
	int dy=1;
	while(tmp--) {
		if(q==h || q==0) {
			dy = -dy;
			tmp %= 2*h;
		}
		q += dy;
	}

	cout << p << ' ' << q;

	return 0;
}