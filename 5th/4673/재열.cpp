#include <iostream>

using namespace std;

int main() {
	for (int n = 1; n <= 10000; n++) {
		int signal = false;
		for (int x = 0; x <= 9; x++) {
			for (int y = 0; y <= 9; y++) {
				for (int z = 0; z <= 9; z++) {
					for (int w = 0; w <= 9; w++) {
						if (1001*x + 101*y + 11*z + 2*w == n) {
							signal = true;
							break;
						}
					}
					if (signal) break;
				}
				if (signal) break;
			}
			if (signal) break;
		}
		if (!signal) {
			cout << n << endl;
		}
	}

	return 0;
}

