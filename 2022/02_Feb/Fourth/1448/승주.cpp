#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>

using namespace std;

int main() {
	int N;
	int x;
	vector <int> V;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		V.push_back(x);
	}
	sort(V.begin(), V.end(), greater<>());
	int i = 0;
	while (1) {
		if (i == N - 2) {
			cout << -1;
			break;
		}
		if (V[i] < V[i + 1] + V[i + 2]) {
			cout << V[i] + V[i + 1] + V[i + 2];
			break;
		}
		i++;
	}
}
