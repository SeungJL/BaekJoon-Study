// 백준 16433번 주디와 당근농장
// 2022년 01월 25일

#include <iostream>

using namespace std;

int main() {

	int n, x, y;
	cin >> n >> x >> y;

	if ((x + y) % 2 == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((i + j) % 2 == 0)
					cout << "v";
				else
					cout << ".";
			}
			cout << endl;
		}
	}
	else if ((x + y) % 2 == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((i + j) % 2 == 0)
					cout << ".";
				else
					cout << "v";
			}
			cout << endl;
		}
	}

	return 0;
}
