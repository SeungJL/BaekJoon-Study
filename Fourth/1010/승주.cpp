#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T;
	int M, N;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		int ans = 1;
		int k = 1;
		for (int j = 0; j < N; j++) {
			ans *= M;
			M--;
			ans /= k;
			k++;
		}
		cout << ans << endl;
	}

}
