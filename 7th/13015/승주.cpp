#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <cmath>

using namespace std;

int main() {
	int N;
	int k;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < 4 * N - 3; j++) {
			if (i == 0) {
				if (j < N) { cout << '*'; }
				else if (j >= 3 * N - 3) { cout << '*'; }
				else { cout << " "; }
			}
			else {
				if (j == i || j == i + N - 1 || j == 4 * N - 4 - i || j == 4 * N - 4 - i - N + 1) { cout << '*'; }
				else if (j > 4 * N - 4 - i) {
					break;
				}
				else { cout << " "; }
			}
		}
		cout << endl;
	}
	for (int j = 0; j < 4 * N - 3; j++) {
		if (j == N - 1 || j == N - 1 + N - 1 || j == N - 1 + N - 1 + N - 1) { cout << '*'; }
		else if (j > 3 * N - 3) {
			break;
		}
		else { cout << " "; }
	}
	cout << endl;
	k = 1;
	for (int i = N - 1; i < 2 * N - 2; i++) {
		for (int j = 0; j < 4 * N - 3; j++) {
			if (i == 2 * N - 3) {
				if (j < N) { cout << '*'; }
				else if (j >= 3 * N - 3) { cout << '*'; }
				else { cout << " "; }
			}
			else {
				if (j == i - k || j == i - k + N - 1 || j == 4 * N - 4 - i + k || j == 4 * N - 4 - i + k - N + 1) {
					cout << '*';
				}
				else if (j > 4 * N - 4 - i + k) {
					break;
				}
				else {
					cout << " ";
				}
			}
		}
		cout << endl;
		k += 2;
	}
}