#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	vector <int> V;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		V.push_back(i);
	}
	do {
		for (int i = 0; i < N; i++) {
			cout << V[i] << " ";
		}
		cout << '\n';
	} while (next_permutation(V.begin(), V.end()));
}