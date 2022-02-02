#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	char list[51][51] = {};
	int a = 0; //ї­
	int b = 0;//За
	int x = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> list[i][j];
			if (list[i][j] == 'X') {
				x = 1;
			}
			if (j == m - 1) {
				if (x == 0) { a++; }
				else { x = 0; }
			}
		}
	}
	x = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (list[j][i] == 'X') {
				x = 1;
			}
			if (j == n - 1) {
				if (x == 0) { b++; }
				else { x = 0; }
			}
		}
	}
	cout << max(a, b);
}