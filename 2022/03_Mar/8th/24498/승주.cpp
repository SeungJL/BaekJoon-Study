#include <iostream>
#include <algorithm>
#include <stdio.h>
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
	vector <long long> V;
	cin >> N;
	long long x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		V.push_back(x);
	}
	long long Max = 0;
	for (int i = 1; i < N - 1; i++) {
		if (V[i - 1] >= 1 && V[i + 1] >= 1) {
			if (V[i] + min(V[i - 1], V[i + 1]) > Max) {
				Max = V[i] + min(V[i - 1], V[i + 1]);
			}
		}
	}
	if (Max == 0) {
		for (int i = 0; i < N; i++) {
			if (V[i] > Max) {
				Max = V[i];
			}
		}
	}
	cout << max({ V[0],V[N - 1],Max });
}