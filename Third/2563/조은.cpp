#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

bool colored[100][100] = { false };

int main() {
	//freopen("input.txt", "rt", stdin);
	int N;
	cin >> N;

	int x, y, res = 0;
	while (N--) {
		cin >> x >> y;
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				if (!colored[i][j]) {
					++res;
					colored[i][j] = true;
				}
			}
		}
	}
	
	cout << res;
	
	return 0;
}
