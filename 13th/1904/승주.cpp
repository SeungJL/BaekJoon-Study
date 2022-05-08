#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector <int> V(1000001);

	V[0] = 1;
	V[1] = 1;
	V[2] = 2;

	for (int i = 3; i <= N; i++) {
		V[i] = 2 * V[i - 2] + V[i - 3];
		if (V[i] > 15746) { V[i] %= 15746; }
	}
	cout << V[N] << endl;
}