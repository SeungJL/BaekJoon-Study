#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <cmath>

using namespace std;

int main() {
	int Max1 = 0;
	int Max2 = 0;
	int visit[1001] = {};
	int N;
	int ans = 0;
	int L;
	int A, B;
	cin >> L;
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		int ans = 0;
		cin >> a >> b;
		if (b - a + 1 > Max2) {
			Max2 = b - a + 1;
			A = i + 1;
		}
		for (int j = a; j <= b; j++) {
			if (visit[j] == 0) {
				visit[j] = 1;
				ans++;
			}
		}
		if (ans > Max1) {
			Max1 = ans;
			B = i + 1;
		}
	}
	cout << A << endl << B;
}